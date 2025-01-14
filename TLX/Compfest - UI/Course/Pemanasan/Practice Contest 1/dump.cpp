#include <iostream>
#include <cstdlib> // for std::exit
#include <algorithm> // for std::max and std::min

using namespace std;

// Global variables
int X, Y, N;
int min_x, max_x, min_y, max_y;
int radar_x, radar_y;

// Function to handle the radar query
pair<int, char> process_query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    cout.flush();
    
    int quadrant;
    char move;
    cin >> quadrant >> move;
    return {quadrant, move};
}

// Function to make the final guess
void make_guess(int x, int y) {
    cout << "! " << x << " " << y << endl;
    cout.flush();
    exit(0); // Terminate the program
}

int main() {
    // Read the initial input
    cin >> X >> Y >> N;
    
    // Initialize the search space
    min_x = 1;
    max_x = X;
    min_y = 1;
    max_y = Y;
    
    // Start with an arbitrary point in the grid
    radar_x = (max_x + min_x) / 2;
    radar_y = (max_y + min_y) / 2;
    
    for (int i = 0; i < N; ++i) {
        // Place the radar and get feedback
        auto [quadrant, move] = process_query(radar_x, radar_y);
        
        // Update the bounds based on quadrant information
        switch (quadrant) {
            case 1:
                min_x = radar_x + 1;
                min_y = radar_y;
                break;
            case 2:
                max_x = radar_x;
                min_y = radar_y;
                break;
            case 3:
                max_x = radar_x;
                max_y = radar_y - 1;
                break;
            case 4:
                min_x = radar_x + 1;
                max_y = radar_y - 1;
                break;
        }
        
        // Update radar position based on the move
        switch (move) {
            case 'U':
                radar_y++;
                break;
            case 'D':
                radar_y--;
                break;
            case 'L':
                radar_x--;
                break;
            case 'R':
                radar_x++;
                break;
            case 'S':
                // No change in position
                break;
        }
        
        // Ensure radar is within grid bounds
        radar_x = max(1, min(radar_x, X));
        radar_y = max(1, min(radar_y, Y));
    }
    
    // At this point, the range should have narrowed down
    // Make the final guess (in practice, you will use the final position)
    make_guess(radar_x, radar_y);
    
    return 0;
}
