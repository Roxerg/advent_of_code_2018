import re

from pprint import pprint

def parse_claim(claim):
    groups = re.match(r'#(?P<id>\d+) @ (?P<left>\d+),(?P<top>\d+): (?P<width>\d+)x(?P<height>\d+)', claim)
    return {
        "id": int(groups.group('id')),
        "left": int(groups.group('left')),
        "top": int(groups.group('top')),
        "width": int(groups.group('width')),
        "height": int(groups.group('height'))
    }

def part1(claims):
    claims = [parse_claim(claim) for claim in claims.split('\n')]
    grid = []
    for row in range(1000):
        grid.append(["." for col in range(1000)])

    count = 0
    
    for claim in claims:
        for row in range(claim['top'], claim['top'] + claim['height']):
            for col in range(claim['left'], claim['left'] + claim['width']):
                if grid[row][col] == ".":
                    grid[row][col] = str(claim['id'])
                elif grid[row][col] != "X":
                    grid[row][col] = "X"
                    count += 1

    return count

def part2(claims):
    claims = [parse_claim(claim) for claim in claims.split('\n')]
    grid = []
    for row in range(1000):
        grid.append(["." for col in range(1000)])
    
    non_overlapped = set()

    for claim in claims:
        has_overlapped = False
        for row in range(claim['top'], claim['top'] + claim['height']):
            for col in range(claim['left'], claim['left'] + claim['width']):
                if grid[row][col] == ".":
                    grid[row][col] = claim['id']
                else:
                    if grid[row][col] in non_overlapped:
                        non_overlapped.remove(grid[row][col])
                    grid[row][col] = "X"
                    has_overlapped = True
        
        if not has_overlapped:
            non_overlapped.add(claim['id'])

    return list(non_overlapped)[0]

if __name__ == "__main__":
    with open('input.txt') as problem:
        problem_text = problem.read()
        print(part1(problem_text))
        print(part2(problem_text))