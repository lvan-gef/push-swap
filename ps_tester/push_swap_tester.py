#! /usr/bin/env python3

from pathlib import Path
import argparse
import random
import sys
import subprocess
import string

INT_MAX = 2147483647
INT_MIN = -2147483648

def run_ps(ps_exe: Path, args: str, should_pass: bool = True, is_silend: bool = True):
        result = subprocess.run(f'{ps_exe} {args}', shell=True, capture_output=True, text=True)
        if should_pass:
            assert result.returncode == 0

            if is_silend:
                assert result.stdout == ''
                assert result.stderr == ''
            else:
                pass
        else:
            assert result.returncode != 0

            if is_silend:
                assert result.stdout == ''
                assert result.stderr == ''
            else:
                assert result.stdout == ''
                assert result.stderr == 'Error\n'


def run_checker(ps_exe: Path, checker: Path, args: str, should_pass: bool = True):
    result = subprocess.run(f'ARG="{args}"; {ps_exe} $ARG | tee moves.txt | {checker} $ARG', shell=True, capture_output=True, text=True)
    if should_pass:
        assert(result.returncode == 0)
        assert(result.stdout == 'OK\n')
        assert(result.stderr == '')


def random_numbers(size: int) -> str:
    if size < 1:
        return ''

    numbers = random.sample(range(INT_MIN, INT_MAX + 1), k=size)
    # not sure of sample always is in unsorted order, so we check it
    # if in order suffle it till it is not anymore
    if (len(numbers) > 1):
        while all(numbers[i] <= numbers[i + 1] for i in range(len(numbers) - 1)):
            random.shuffle(numbers)

    return ' '.join(str(nbr) for nbr in numbers)


def white_space_test(ps_exe: Path):
    white_space_list = ['', ' ', '\t']

    print('Test white spaces as input')
    for ws in white_space_list:
        for counter in range(5):
            empty = ws.join('' for _ in range(counter))
            run_ps(ps_exe=ps_exe, args=empty, should_pass=False, is_silend=True)
    print('Passed white spaces as input\n')


def non_numbers_test(ps_exe: Path):
    non_numbers = f'{string.ascii_letters} \t,\\.'

    print('Test non numbers as input')
    args = [''.join(random.choices(non_numbers, k=random.randint(1, 10))) for _ in range(5)]
    args.append('-')
    args.append('.')
    for index in range(len(args)):
        combinde_args = ' '.join(x for x in args[:index + 1])
        run_ps(ps_exe=ps_exe, args=combinde_args, should_pass=False, is_silend=False)
    print('Passed non numbers as input\n')


def decimal_test(ps_exe: Path):
    decimals = [random.random() for _ in range(10)]

    print('Test float as input')
    for index, _ in enumerate(decimals):
        combinde_args = ' '.join(str(x) for x in decimals[:index + 1])
        run_ps(ps_exe=ps_exe, args=combinde_args, should_pass=False, is_silend=False)
    print('Passed float as input\n')


def test_args(ps_exe: Path):
    white_space_test(ps_exe=ps_exe)
    non_numbers_test(ps_exe=ps_exe)
    decimal_test(ps_exe=ps_exe)


def test_sorting(ps_exe: Path, checker: Path, retry: int):
    test_sizes = [1, 2, 3, 4, 5, 10, 11, 20 ,25, 31, 38, 40, 41, 50, 55, 60, 69, 70, 71, 80, 85, 90, 96, 100, 201, 333, 404, 500]

    for size in test_sizes:
        print(f'Testing sorting with {size} numbers')
        moves = []
        for _ in range(retry):
            nbrs = random_numbers(size=size)
            run_checker(ps_exe=ps_exe, checker=checker, args=nbrs, should_pass=True)
            result = subprocess.run('cat moves.txt | wc -l', shell=True, capture_output=True, text=True)
            moves.append(int(result.stdout))
        print(f'min: {min(moves)}, avg: {sum(moves) // len(moves)}, max: {max(moves)}\n')

    print('Test numbers more then INT MAX and INT MIN')
    nbrs = random.sample(range(-2147483648, INT_MAX + 1), k=100)
    out_of_range = [INT_MAX + 1, INT_MAX + 12, INT_MAX + 42, INT_MIN - 1, INT_MIN - 12, INT_MIN - 42]
    for index, nbr in enumerate(out_of_range):
        nbrs.insert(index, nbr)
        combinde_args = ' '.join(str(nbr) for nbr in nbrs)
        run_ps(ps_exe=ps_exe, args=combinde_args, should_pass=False, is_silend=False)
        result = subprocess.run(f'ARG="{combinde_args}"; {ps_exe} $ARG', shell=True, capture_output=True, text=True)
        nbrs.remove(nbr)
    print('Passed numbers more then INT MAX and INT MIN')

    subprocess.run('rm moves.txt', shell=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(prog='ps_test', description='A simple push swap tester for codam', epilog='Lets sort numbers')
    parser.add_argument('ps', help='The path to the push swap executable', type=Path)
    parser.add_argument('ch', help='The path to the checker of codam', type=Path)
    parser.add_argument('-r', '--retry', type=int, default=100, help='How many times we retry a size. Is for dynamic sorting so we get a avg of the moves')
    args = parser.parse_args()

    codam_checkers_bin = Path(args.ch)
    if not codam_checkers_bin.exists():
        print(f'Missing the checker provided by codam at this path: {codam_checkers_bin}', file=sys.stderr)
        exit(1)

    user_ps_path = Path(args.ps)
    if not user_ps_path.exists():
        print(f'Missing the push swap executable on path: {user_ps_path}', file=sys.stderr)
        exit(1)

    if args.retry < 1:
        print(f'Many retry must be 1 or more', file=sys.stderr)
        exit(1)

    test_args(ps_exe=user_ps_path.resolve())
    test_sorting(ps_exe=user_ps_path.resolve(), checker=codam_checkers_bin.resolve(), retry=args.retry)
