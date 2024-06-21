#include <iostream>
#include <vector>
using namespace std;

class JobSequencing
{
private:
    vector<int> profits;
    vector<int> deadlines;
    vector<int> sequence;
    int timeLimit;

    bool sequenceisFull() {
        for (int element : sequence) {
            if (element == -1) {
                return false;
            }
        }
        return true;
    }

    int findSlot(int deadline) {
        for (int i = deadline - 1; i >= 0; --i) {
            if (sequence[i] == -1) {
                return i; // Return the index of the empty slot
            }
        }
        return -1; // No empty slot found before the deadline
    }

    void generateSequence() {
        int index = 0;
        while (!sequenceisFull() && index < profits.size()) {
            if (deadlines[index] <= timeLimit) {
                int slot = findSlot(deadlines[index]);
                if (slot != -1) {
                    sequence[slot] = index;
                }
            }
            index++;
        }
    }

    void bubbleSort() {
        int n = profits.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (profits[j] < profits[j + 1]) {
                    // Swap profits[j] and profits[j + 1]
                    int tempProfit = profits[j];
                    profits[j] = profits[j + 1];
                    profits[j + 1] = tempProfit;

                    // Swap deadlines[j] and deadlines[j + 1]
                    int tempDeadline = deadlines[j];
                    deadlines[j] = deadlines[j + 1];
                    deadlines[j + 1] = tempDeadline;
                }
            }
        }
    }

public:
    JobSequencing(vector<int> profitsArray, vector<int> deadlinesArray, int limit) {
        profits = profitsArray;
        deadlines = deadlinesArray;
        timeLimit = limit;

        // Initialize sequence with -1 to indicate empty slots
        sequence.resize(limit, -1);
    }

    vector<int> getSequence() {
        bubbleSort();
        generateSequence();
        return sequence;
    }
};

int main() {
    vector<int> profits = {100, 19, 27, 25, 15};
    vector<int> deadlines = {2, 1, 2, 1, 3};
    int limit = 3;
    
    JobSequencing jobSeq(profits, deadlines, limit);
    vector<int> sequence = jobSeq.getSequence();

    cout << "Job sequence (indices): ";
    for (int i : sequence) {
        if (i != -1) {
            cout << i << " ";
        }
    }
    cout << endl;

    // Print the actual jobs based on sequence
    cout << "Jobs selected: ";
    for (int i : sequence) {
        if (i != -1) {
            cout << "Profit: " << profits[i] << ", Deadline: " << deadlines[i] << "; ";
        }
    }
    cout << endl;

    return 0;
}
