#! /usr/bin/env python3

import platform
from pathlib import Path
import argparse
import random
import sys
import subprocess
import string


def random_numbers(size: int) -> str:
    if size < 1:
        return ''

    numbers = []
    while len(numbers) != size:
        nbr = random.randint(-2147483648, 2147483647)
        if nbr not in numbers:
            numbers.append(nbr)

    if (size > 1):
        while all(numbers[i] <= numbers[i + 1] for i in range(len(numbers) - 1)):
            random.shuffle(numbers)

    return ' '.join(str(nbr) for nbr in numbers)


def white_space_test(ps_exe: Path):
    white_space_list = ['', ' ', '\t']

    print('Test white spaces as input')
    for ws in white_space_list:
        for counter in range(5):
            empty = ws.join(' ' for _ in range(counter))
            result = subprocess.run(f'{ps_exe}{empty}', shell=True, capture_output=True)
            assert result.stdout.decode() == ''
            assert result.stderr.decode() == ''
            assert result.returncode != 0
    print('Passed white spaces as input\n')


def non_numbers_test(ps_exe: Path):
    non_numbers = f'{string.ascii_letters} \t,\\.'

    print('Test non numbers as input')
    args = [''.join(random.choices(non_numbers, k=random.randint(1, 10))) for _ in range(5)]
    for index in range(len(args)):
        combinde_args = ' '.join(x for x in args[:index + 1])
        result = subprocess.run(f'{ps_exe} {combinde_args}', shell=True, capture_output=True)
        assert result.stdout.decode() == ''
        assert result.stderr.decode() == 'Error\n'
        assert result.returncode != 0
    print('Passed non numbers as input\n')


def decimal_test(ps_exe: Path):
    decimals = [random.random() for _ in range(10)]

    print('Test float as input')
    for index, _ in enumerate(decimals):
        combinde_args = ' '.join(str(x) for x in decimals[:index + 1])
        result = subprocess.run(f'{ps_exe} {combinde_args}', shell=True, capture_output=True)
        assert result.stdout.decode() == ''
        assert result.stderr.decode() == 'Error\n'
        assert result.returncode != 0
    print('Passed float as input\n')


def test_args(ps_exe: Path):
    white_space_test(ps_exe=ps_exe)
    non_numbers_test(ps_exe=ps_exe)
    decimal_test(ps_exe=ps_exe)


def test_sorting(ps_exe: Path, checker: Path, retry: int):
    test_sizes = [1, 2, 3, 4, 5, 10, 11, 20 ,25, 31, 38, 40, 41, 50, 55, 60, 69, 70, 71, 80, 85, 90, 96, 100, 201, 333, 404, 500]

    for size in test_sizes:
        moves = []
        print(f'Testing sorting with {size} numbers')
        for _ in range(retry):
            nbrs = random_numbers(size=size)
            result = subprocess.run(f'ARG="{nbrs}"; {ps_exe} $ARG | tee moves.txt | {checker} $ARG', shell=True, capture_output=True)
            assert(result.stdout.decode() == 'OK\n')

            result = subprocess.run('cat moves.txt | wc -l', shell=True, capture_output=True)
            moves.append(int(result.stdout.decode()))
        print(f'min: {min(moves)}, avg: {sum(moves) // len(moves)}, max: {max(moves)}\n')

    subprocess.run('rm moves.txt', shell=True)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(prog='ps_test', description='A simple push swap tester for codam', epilog='Lets sort numbers')
    parser.add_argument('ps', help='The path to the push swap executable', type=Path)
    parser.add_argument('-r', '--retry', type=int, default=100, help='How many times we retry a size. Is for dynamic sorting so we get a avg of the moves')
    parser.add_argument('ch', help='The path to the checker of codam', type=Path)
    args = parser.parse_args()

    codam_checkers_bin = Path(args.ch)
    os_name = platform.system().lower()

    if not codam_checkers_bin.exists():
        print(f'Missing the checker provided by codam at this path: {codam_checkers_bin}', file=sys.stderr)
        exit(1)

    user_ps_path = Path(args.ps)
    if not user_ps_path.exists():
        print(f'Missing the push swap executable on path: {user_ps_path}')
        exit(1)

    if args.retry < 1:
        print(f'Many retry must be 1 or more', file=sys.stderr)
        exit(1)

    test_args(ps_exe=user_ps_path)
    test_sorting(ps_exe=user_ps_path, checker=codam_checkers_bin, retry=args.retry)
