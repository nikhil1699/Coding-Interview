import copy
import time
import sys
from collections import deque
import heapq


class HeapQueue():
    def __init__(self):
        self.elems = []
        self.index = 0

    def put(self, elem, priority):
        heapq.heappush(self.elems, (-priority, self.index, elem))
        self.index += 1

    def get(self):
        return heapq.heappop(self.elems)[2]

    def __contains__(self, key):
        for elem in elems:
            if elem[1] == key: return True
        return False

    def empty(self):
        return not self.elems


# 0 = unused, 1 = peg, 2 = empty space
dfs_board = [0, 0, 2, 2, 2, 0, 0,
             0, 2, 2, 2, 2, 1, 0,
             1, 2, 1, 1, 1, 2, 2,
             1, 1, 1, 2, 1, 2, 2,
             1, 1, 2, 2, 1, 2, 2,
             0, 2, 1, 2, 1, 1, 0,
             0, 0, 1, 2, 1, 0, 0]


dfs_goal = [0, 0, 2, 2, 2, 0, 0,
            0, 2, 2, 1, 2, 2, 0,
            2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2,
            0, 2, 2, 2, 2, 2, 0,
            0, 0, 2, 2, 2, 0, 0]

init_board = [0, 0, 1, 1, 1, 0, 0,
              0, 1, 1, 1, 1, 1, 0,
              1, 1, 1, 2, 1, 1, 1,
              1, 1, 1, 1, 1, 1, 1,
              1, 1, 1, 1, 1, 1, 1,
              0, 1, 1, 1, 1, 1, 0,
              0, 0, 1, 1, 1, 0, 0]

bfs_board =  [0, 0, 2, 2, 2, 0, 0,
              0, 2, 2, 2, 2, 1, 0,
              1, 1, 2, 2, 1, 2, 2,
              1, 1, 1, 2, 1, 2, 2,
              1, 2, 2, 1, 1, 2, 2,
              0, 2, 2, 2, 1, 1, 0,
              0, 0, 2, 2, 1, 0, 0]

bfs_goal = [0, 0, 2, 2, 2, 0, 0,
            0, 2, 2, 1, 2, 2, 0,
            2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2,
            0, 2, 2, 2, 2, 2, 0,
            0, 0, 2, 2, 2, 0, 0]

legend = [0 , 1 , 2 , 3 , 4 , 5 , 6 ,
          7 , 8 , 9 , 10, 11, 12, 13,
          14, 15, 16, 17, 18, 19, 20,
          21, 22, 23, 24, 25, 26, 27,
          28, 29, 30, 31, 32, 33, 34,
          35, 36, 37, 38, 39, 40, 41,
          42, 43, 44, 45, 46, 47, 48]


class State():
    def __init__(self, board, goal, xSize, ySize, pegs):
        self.board = board
        self.goal = goal
        self.xSize = xSize
        self.ySize = ySize
        self.children = 0
        self.pegs = pegs
        self.isolated = 0
        self.parent = None
        if self.parent is not None:
            self.pegs = pegs - 1
            self.isolated = parent.isolated

    def is_goal(self):
        return self.board == self.goal

    # moves element at x1, y1 into x2, y2
    def move(self, x1, y1, x2, y2):
        # y = index / width. x = index % width;
        # cell = y * xSize  + x
        if not self.is_cell_valid(x1, y1) or not self.is_cell_valid(x2, y2):
            return None
        else:
            c1 = y1 * self.xSize + x1
            c2 = y2 * self.xSize + x2
            tmp = self.board[c2]
            self.board[c2] = self.board[c1]
            self.board[c1] = 2
            return tmp

    def remove(self, x, y):
        if not self.is_cell_valid(x, y):
            return None
        else:
            c = y * self.xSize + x
            tmp = self.board[c]
            self.board[c] = 2
            self.pegs -= 1
            return tmp

    def is_cell_valid(self, x, y):
        return (x < self.xSize and x >= 0) and (y < self.ySize and y >= 0)

    def get_isolated(self):
        return self.isolated

    def is_valid(self):
        self.todo = false

    def cost(self, state):
        return 1

    def __str__(self):
        X, Y = self.xSize, self.ySize
        out = ''
        for i in range(0, len(self.board)):
            s = ''
            if i % X == 0 and i != 0:
                out += '\n'
            if self.board[i] == 2:
                s += 'O'
            elif self.board[i] == 0:
                s += '-'
            elif self.board[i] == 1:
                s += '*'
            out += s
        return out

    def __eq__(self, other):
        return self.board == other.board

    def __hash__(self):
        return hash(tuple(self.board))


def count_pegs(board):
    count = 0
    for peg in board:
        if peg == 1: count += 1
    return count


def get_successors(state):
    children, moves = [], []
    count = 0
    isolated = 0
    for cell in range(0, len(state.board)):
        if state.board[cell] == 1:
            moveN = move_north(state, cell)
            moveS = move_south(state, cell)
            moveW = move_west(state, cell)
            moveE = move_east(state, cell)
            moves.append(moveN)
            moves.append(moveS)
            moves.append(moveW)
            moves.append(moveE)
            if moveN is None and moveS is None and moveE is None and moveW is None:
                isolated += 1
    for move in moves:
        if move:
            children.append(move)
            count += 1
    state.children = count
    state.isolated = isolated
    return children


def move_north(state, cell):
    newState = State(list(state.board), state.goal, state.xSize, state.ySize, state.pegs)
    y = int(cell / state.xSize)
    x = cell % state.xSize

    # check if target cell is valid
    if not newState.is_cell_valid(x, y-2):
        return None
    else:
        newCell = (y-2) * state.xSize + x
        btwCell = (y-1) * state.xSize + x
        if newState.board[newCell] != 2 or newState.board[btwCell] != 1:
            return None
        else:
            newState.remove(x, y-1)
            newState.move(x, y, x, y-2)
            newState.parent = state
            return newState


def move_south(state, cell):
    newState = State(list(state.board), state.goal, state.xSize, state.ySize, state.pegs)
    y = int(cell / state.xSize)
    x = cell % state.xSize

    # check if target cell is valid
    if not newState.is_cell_valid(x, y+2):
        return None
    else:
        newCell = (y+2) * state.xSize + x
        btwCell = (y+1) * state.xSize + x
        if newState.board[newCell] != 2 or newState.board[btwCell] != 1:
            return None
        else:
            newState.remove(x, y+1)
            newState.move(x, y, x, y+2)
            newState.parent = state
            return newState


def move_east(state, cell):
    newState = State(list(state.board), state.goal, state.xSize, state.ySize, state.pegs)
    y = int(cell / state.xSize)
    x = cell % state.xSize

    # check if target cell is valid
    if not newState.is_cell_valid(x+2, y):
        return None
    else:
        newCell = y * state.xSize + (x+2)
        btwCell = y * state.xSize + (x+1)
        if newState.board[newCell] != 2 or newState.board[btwCell] != 1:
            return None
        else:
            newState.remove(x+1, y)
            newState.move(x, y, x+2, y)
            newState.parent = state
            return newState


def move_west(state, cell):
    newState = State(list(state.board), state.goal, state.xSize, state.ySize, state.pegs)
    y = int(cell / state.xSize)
    x = cell % state.xSize

    # check if target cell is valid
    if not newState.is_cell_valid(x-2, y):
        return None
    else:
        newCell = y * state.xSize + (x-2)
        btwCell = y * state.xSize + (x-1)
        if newState.board[newCell] != 2 or newState.board[btwCell] != 1:
            return None
        else:
            newState.remove(x-1, y)
            newState.move(x, y, x-2, y)
            newState.parent = state
            return newState


def bfs(problem):
    queue, closed = [], set()
    queue.append(problem)
    while queue:
        state = queue.pop()
        if state not in closed:
            closed.add(state)
            if state.is_goal():
                return state
            for newState in get_successors(state):
                queue.insert(0, newState)
    return None


def dfs(problem):
    stack, closed = [], set()
    stack.append(problem)
    while stack:
        state = stack.pop()
        if state not in closed:
            closed.add(state)
            if state.is_goal():
                return state
            for newState in get_successors(state):
                stack.append(newState)
    return None


'''
Some ideas for heuristics:
    1. Number of successor nodes
    2. Number of isolated peg's
    3. Less peg's = better
    4. Sum of distances from center
    5. Distance from goal board
    6. Distance between parent and child state
'''


# Always prioritize greatest branch
def heuristic1(goal, state):
    return -len(get_successors(state))


# Always prioritize least isolated
def heuristic2(goal, state):
    return state.get_isolated()


def heuristic3(goal, state):
    return (heuristic1(goal, state) + heuristic2(goal, state)) / 2


def aStar(problem, heuristic):
    hq, origin, cost = HeapQueue(), {}, {}
    hq.put(problem, 0)
    origin[problem], cost[problem] = None, 0

    while not hq.empty():
        state = hq.get()
        if state.is_goal():
            return state
        for child in get_successors(state):
            new_cost = cost[state] + state.cost(child)
            if child not in cost or new_cost < cost[child]:
                cost[child] = new_cost
                priority = heuristic(state.goal, child) + new_cost
                hq.put(child, priority)
                origin[child] = state
                child.parent = state
    return None


def print_solution(solution):
    if not solution:
        print('No solution found')
    else:
        print('Solution found: ')
        path = [solution]
        parent = solution.parent
        while parent:
            path.append(parent)
            parent = parent.parent
        for t in range(len(path)):
            state = path[len(path) - t - 1]
            print('Move: %i' % (t+1))
            print(state)


def bfs_solution():
    print('[===============================BFS Solution===============================]')
    sTime = time.time()
    game = State(bfs_board, bfs_goal, 7, 7, count_pegs(bfs_board))
    print(game)
    solution = bfs(game)
    eTime = time.time()
    print_solution(solution)
    print('Total Time: approx. %s sec \n' % str(eTime - sTime))


def dfs_solution():
    print('[===============================DFS Solution===============================]')
    sTime = time.time()
    game = State(bfs_board, dfs_goal, 7, 7, count_pegs(dfs_board))
    print(game)
    solution = dfs(game)
    eTime = time.time()
    print_solution(solution)
    print('Total Time: approx. %s sec \n' % str(eTime - sTime))


# For comparison with Astar only
def bfs_solution2():
    print('[===============================BFS Solution2===============================]')
    sTime = time.time()
    game = State(bfs_board, dfs_goal, 7, 7, count_pegs(dfs_board))
    print(game)
    solution = bfs(game)
    eTime = time.time()
    print_solution(solution)
    print('Total Time: approx. %s sec \n' % str(eTime - sTime))


def astar_h1_solution():
    print('[===============================A* Heuristic1 Solution===============================]')
    sTime = time.time()
    game = State(bfs_board, dfs_goal, 7, 7, count_pegs(dfs_board))
    print(game)
    solution = aStar(game, heuristic1)
    eTime = time.time()
    print_solution(solution)
    print('Total Time: approx. %s sec \n' % str(eTime - sTime))


def astar_h2_solution():
    print('[===============================A* Heuristic2 Solution===============================]')
    sTime = time.time()
    game = State(bfs_board, dfs_goal, 7, 7, count_pegs(dfs_board))
    print(game)
    solution = aStar(game, heuristic2)
    eTime = time.time()
    print_solution(solution)
    print('Total Time: approx. %s sec \n' % str(eTime - sTime))


def astar_h3_solution():
    print('[===============================A* Heuristic3 Solution===============================]')
    sTime = time.time()
    game = State(bfs_board, dfs_goal, 7, 7, count_pegs(dfs_board))
    print(game)
    solution = aStar(game, heuristic3)
    eTime = time.time()
    print_solution(solution)
    print('Total Time: approx. %s sec \n' % str(eTime - sTime))


def main():
    bfs_solution()
    dfs_solution()
    bfs_solution2()
    astar_h1_solution()
    astar_h2_solution()
    astar_h3_solution()

if __name__ == "__main__":
    main()