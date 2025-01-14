import sys
input = sys.stdin.read
import sys
from collections import deque

# Read the initial input
def init():
    global X, Y, N
    X, Y, N = map(int, input().strip().split())

def process_query(x, y):
    print(f"? {x} {y}")
    sys.stdout.flush()
    response = input().strip().split()
    quadrant = int(response[0])
    move = response[1]
    return quadrant, move

def make_guess(x, y):
    print(f"! {x} {y}")
    sys.stdout.flush()
    sys.exit()

def main():
    init()
    
    # The grid boundaries
    min_x, max_x = 1, X
    min_y, max_y = 1, Y
    
    # Start with an arbitrary point in the grid
    radar_x, radar_y = (max_x + min_x) // 2, (max_y + min_y) // 2
    
    for _ in range(N):
        # Place the radar
        quadrant, move = process_query(radar_x, radar_y)
        
        # Update the bounds based on quadrant information
        if quadrant == 1:
            min_x = radar_x + 1
            min_y = radar_y
        elif quadrant == 2:
            max_x = radar_x
            min_y = radar_y
        elif quadrant == 3:
            max_x = radar_x
            max_y = radar_y - 1
        elif quadrant == 4:
            min_x = radar_x + 1
            max_y = radar_y - 1
        
        # Update the radar position based on move
        if move == 'U':
            radar_y += 1
        elif move == 'D':
            radar_y -= 1
        elif move == 'L':
            radar_x -= 1
        elif move == 'R':
            radar_x += 1
        elif move == 'S':
            pass  # No change in position
        
        # Ensure radar is within grid bounds
        radar_x = max(1, min(radar_x, X))
        radar_y = max(1, min(radar_y, Y))
    
    # At this point, the range should have narrowed down
    # Make the final guess (in practice, you will use the final position)
    # This is just a placeholder, replace with actual logic to determine the exact location
    make_guess(radar_x, radar_y)

if __name__ == "__main__":
    main()
