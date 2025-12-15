/*
 * Tower of Hanoi - Son's Illegal Move Problem
 * 
 * Problem: Lucas teaches his son the Tower of Hanoi puzzle. After k optimal moves,
 * Lucas takes a break. His son then makes an "illegal" move by literally moving ALL
 * disks from the first rod to the last rod in one move (preserving their order).
 * 
 * Goal: Calculate the minimum number of valid moves needed to complete the puzzle
 * from this potentially invalid state.
 * 
 * Key Concepts:
 * - Tower of Hanoi with n disks requires exactly 2^n - 1 optimal moves
 * - The state after k moves can be encoded/decoded using binary representation
 * - Son's move may create an invalid state (larger disk on top of smaller disk)
 * - We use binary string arithmetic because n can be up to 200,000 (numbers exceed long long)
 */

#include <iostream>
// #include <string>  // string is available without explicit include in most compilers
using namespace std;

const int MAXN = 200005;  // Maximum number of disks (constraint from problem)

// Rod position constants for Tower of Hanoi
const int LEFT_ROD = 0;      // Source rod (where all disks start)
const int MIDDLE_ROD = 1;    // Auxiliary rod (helper rod)
const int RIGHT_ROD = 2;     // Destination rod (goal: all disks here)

/*
 * Reconstruct disk positions from binary-encoded optimal move sequence
 * 
 * Tower of Hanoi moves can be uniquely encoded in binary:
 * - For n disks, we use an n-bit binary number
 * - Each bit represents whether the largest remaining disk has been moved
 * - Bit = 1: disk moved to destination; Bit = 0: disk still on source
 * 
 * Example: n=3, binary="010" (decimal 2)
 * - Bit 0 (disk 3): 0 -> Disk 3 still on left rod
 * - Bit 1 (disk 2): 1 -> Disk 2 has been moved to middle rod
 * - Bit 2 (disk 1): 0 -> Disk 1 on right rod (part of moving smaller disks)
 * 
 * Parameters:
 *   numDisks - total number of disks in the puzzle
 *   movesBinary - binary string representing the number of optimal moves done
 *   diskPosition - output array where diskPosition[i] = rod number for disk i
 */
void reconstructDiskPositions(int numDisks, const string& movesBinary, int diskPosition[]) {
    // Initialize all disk positions to rod 0 (left) - starting position
    for(int i = 0; i <= numDisks; i++) {
        diskPosition[i] = 0;
    }
    
    // Pad binary string with leading zeros to match number of disks
    // Example: if numDisks=5 and movesBinary="101", pad to "00101"
    string paddedMoves = movesBinary;
    while((int)paddedMoves.size() < numDisks) paddedMoves = "0" + paddedMoves;
    
    // Decode move sequence: process from largest disk to smallest
    // Track which rods serve as source, destination, and auxiliary for current sub-problem
    int sourceRod = LEFT_ROD, destinationRod = RIGHT_ROD, auxiliaryRod = MIDDLE_ROD;
    
    for(int i = 0; i < numDisks; i++) {
        int currentDisk = numDisks - i;  // Start with largest disk
        
        if(paddedMoves[i] == '1') {
            // Bit = 1: This disk has been moved to its destination
            diskPosition[currentDisk] = destinationRod;
            // After moving, the source and auxiliary rods swap roles for smaller disks
            int temp = sourceRod; sourceRod = auxiliaryRod; auxiliaryRod = temp;
        } else {
            // Bit = 0: This disk hasn't been moved yet, still on source
            diskPosition[currentDisk] = sourceRod;
            // Destination and auxiliary swap roles for smaller disks
            int temp = destinationRod; destinationRod = auxiliaryRod; auxiliaryRod = temp;
        }
    }
}

/*
 * Binary String Arithmetic Helpers
 * 
 * Why binary strings instead of integers?
 * - Problem allows n up to 200,000
 * - Calculations involve 2^n which can be 2^200000 (impossibly large for any integer type)
 * - Solution: treat binary numbers as strings, perform digit-by-digit arithmetic
 * 
 * Example: "101" + "11" = "1000" (5 + 3 = 8 in decimal)
 */

/*
 * Add two binary numbers represented as strings
 * 
 * Algorithm: Similar to manual addition, process digits right-to-left with carry
 * Example: "1101" + "1011" = "11000" (13 + 11 = 24)
 */
string addBinaryStrings(string a, string b) {
    string result;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    
    // Add digit by digit from right to left (least significant to most significant)
    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if(i >= 0) sum += a[i--] - '0';  // Add digit from first number
        if(j >= 0) sum += b[j--] - '0';  // Add digit from second number
        result = char('0' + sum % 2) + result;  // Append current bit to result
        carry = sum / 2;  // Carry for next position (1 if sum >= 2)
    }
    
    // Remove leading zeros (e.g., "0011" becomes "11")
    int firstNonZero = result.find_first_not_of('0');
    return firstNonZero == -1 ? "0" : result.substr(firstNonZero);
}

/*
 * Multiply two binary numbers represented as strings
 * 
 * Algorithm: Shift-and-add method (binary long multiplication)
 * - For each '1' bit in multiplier, add shifted multiplicand to result
 * - Example: "101" × "11" = "101" + "1010" = "1111" (5 × 3 = 15)
 */
string multiplyBinaryStrings(string a, string b) {
    string result = "0";
    
    // Iterate through multiplier bits from right to left
    for(int i = b.size() - 1; i >= 0; i--) {
        if(b[i] == '1') {
            // Shift multiplicand left by (b.size() - 1 - i) positions
            string shiftedValue = a + string(b.size() - 1 - i, '0');
            result = addBinaryStrings(result, shiftedValue);  // Add shifted value to result
        }
    }
    
    return result;
}

/*
 * Returns the number of optimal moves for n disks in Tower of Hanoi
 * Formula: 2^n - 1 (represented as n ones in binary)
 * 
 * Examples:
 * - n=3: "111" (7 moves to solve 3-disk puzzle)
 * - n=5: "11111" (31 moves to solve 5-disk puzzle)
 */
string optimalMovesForNDisks(int n) {
    return n == 0 ? "0" : string(n, '1');
}

/*
 * Returns binary representation of 2^n
 * Result: "1" followed by n zeros
 * 
 * Examples:
 * - n=0: "1" (2^0 = 1)
 * - n=3: "1000" (2^3 = 8)
 * - n=5: "100000" (2^5 = 32)
 */
string binaryPowerOf2(int n) {
    return "1" + string(n, '0');
}

/*
 * Calculate remaining moves needed to complete the Tower of Hanoi puzzle
 * 
 * Key Insight: Remaining moves only depend on disks NOT yet on destination
 * - If k disks remain to be moved, we need exactly 2^k - 1 moves
 * - Doesn't matter which disks or their current positions
 * 
 * Example: If 3 disks are still not on RIGHT_ROD, need 2^3-1 = 7 moves
 */
string calculateRemainingMoves(int numDisks, const int diskPosition[]) {
    // Count how many disks are not yet on the destination rod (right rod)
    int disksNotOnDestination = 0;
    for(int i = 1; i <= numDisks; i++) {
        if(diskPosition[i] != RIGHT_ROD) {
            disksNotOnDestination++;
        }
    }
    
    // If all disks already on destination, no moves needed
    if(disksNotOnDestination == 0) return "0";
    
    // Moving k disks optimally requires 2^k - 1 moves
    return optimalMovesForNDisks(disksNotOnDestination);
}

int main() {
    int numDisks;
    string optimalMovesDone;
    cin >> numDisks >> optimalMovesDone;
    
    /*
     * SPECIAL CASE: No moves done yet (k=0)
     * Father hasn't moved any disks, all disks on left rod
     * Son's move shifts all disks to right rod (destination) → puzzle solved instantly!
     */
    if(optimalMovesDone == "0") {
        cout << "0\n";
        return 0;
    }
    
    /*
     * STEP 1: Reconstruct disk positions after father's k optimal moves
     * Decode binary string k to determine where each disk is currently located
     */
    int diskPositionBeforeSonMove[MAXN];
    reconstructDiskPositions(numDisks, optimalMovesDone, diskPositionBeforeSonMove);
    
    /*
     * STEP 2: Simulate son's illegal move
     * Son moves ALL disks from left rod (0) to right rod (2)
     * This violates Tower of Hanoi rules - larger disks may land on smaller ones!
     */
    int diskPositionAfterSonMove[MAXN];
    // First, copy all positions
    for(int i = 0; i <= numDisks; i++) {
        diskPositionAfterSonMove[i] = diskPositionBeforeSonMove[i];
    }
    
    // Then, move all disks from left rod to right rod
    for(int i = 1; i <= numDisks; i++) {
        if(diskPositionBeforeSonMove[i] == LEFT_ROD) {
            diskPositionAfterSonMove[i] = RIGHT_ROD;
        }
    }
    
    /*
     * STEP 3: Detect invalid stacking (rule violation)
     * Invalid stack occurs when:
     * - A larger disk was on LEFT_ROD before son's move
     * - A smaller disk was already on RIGHT_ROD
     * - After son's move, larger disk is now on RIGHT_ROD on top of smaller disk
     * 
     * Example: Disk 3 on left, Disk 1 on right → Son moves → Disk 3 lands on Disk 1 (INVALID!)
     */
    int problemDisk = -1;
    
    for(int largerDisk = numDisks; largerDisk >= 1; largerDisk--) {
        // Only consider disks that were moved from left rod by son
        if(diskPositionBeforeSonMove[largerDisk] != LEFT_ROD) continue;
        if(diskPositionAfterSonMove[largerDisk] != RIGHT_ROD) continue;
        
        // Check if there's a smaller disk that was already on right rod
        for(int smallerDisk = 1; smallerDisk < largerDisk; smallerDisk++) {
            if(diskPositionBeforeSonMove[smallerDisk] == RIGHT_ROD && 
               diskPositionAfterSonMove[smallerDisk] == RIGHT_ROD) {
                // Found invalid stacking: larger disk on top of smaller disk
                problemDisk = largerDisk;
                break;
            }
        }
        if(problemDisk != -1) break;
    }
    
    /*
     * STEP 4a: VALID STATE - No rule violations
     * Simply count disks not on destination and calculate remaining optimal moves
     */
    if(problemDisk == -1) {
        string remainingMoves = calculateRemainingMoves(numDisks, diskPositionAfterSonMove);
        cout << remainingMoves << "\n";
        return 0;
    }
    
    /*
     * STEP 4b: INVALID STATE - Fix the stacking violation
     * 
     * Strategy: Must move disks off the invalid stack, then rebuild properly
     * 
     * Categorize all disks smaller than problemDisk into two groups:
     * - Set A (already moved): Disks NOT on left rod before son's move (already processed by father)
     * - Set C (trapped): Disks that WERE on left rod before son's move (now trapped under problemDisk)
     * 
     * Formula: (2^A - 1) + (2^(d-1) - 1)
     * - First term: Move set A off to access problemDisk
     * - Second term: Move problemDisk and all smaller disks properly to destination
     */
    int numDisksAlreadyMoved = 0;  // Count of disks in set A
    int numDisksTrapped = 0;       // Count of disks in set C (unused in formula but kept for clarity)
    
    for(int i = 1; i < problemDisk; i++) {
        if(diskPositionBeforeSonMove[i] == LEFT_ROD) {
            numDisksTrapped++;
        } else {
            numDisksAlreadyMoved++;
        }
    }
    
    // Calculate total cost: moves to clear + moves to rebuild
    string totalCost = addBinaryStrings(
        optimalMovesForNDisks(numDisksAlreadyMoved),  // 2^A - 1
        optimalMovesForNDisks(problemDisk - 1)         // 2^(d-1) - 1
    );
    
    cout << totalCost << "\n";
    return 0;
}
