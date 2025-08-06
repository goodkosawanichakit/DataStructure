#include <iostream>
#include <stack>
#include <vector>
#include <string>

/*
vector <process*> proccesses = {
  {P1, A = 2, T = 5}, {P2, A = 3, T = 2}, {P3, A = 2, T = 3}, {P4, A = 8, T = 2}}
}
__________________________________________________________________________________________________________
| Time |  T1  |  T2  |  T3  |  T4  |  T5  |  T6  |  T7  |  T8  |  T9  |  T10 |  T11 |  T12 |  T13 |  T14 |  
|  P1  |      |  XX  |  XX  |  XX  |  XX  |  XX  |      |      |      |      |      |      |      |      |
|  P2  |      |      |      |      |      |      |      |      |      |      |      |      |  XX  |  XX  |
|  P3  |      |      |      |      |      |      |  XX  |  XX  |  XX  |  XX  |      |      |      |      |  
|  P4  |      |      |      |      |      |      |      |      |      |      |  XX  |  XX  |      |      |
|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|
*/

struct Process {
  std::string PID;
  int A, T;
};

class ProcessScheduling {
  private:
    std::vector<Process*> processes;
    std::stack<Process*> processes_stack;

    void loadprocess(int time) {
      if(processes.empty()) return;
      for (auto it = processes.begin(); it != processes.end(); ) {
        Process* temp = *it;
        if (temp->A == time) {
          processes_stack.push(temp);  
          it = processes.erase(it);
        } else {
          ++it;
        }
      }
    }

  public:
    void arrive(Process* new_process) {
      processes.push_back(new_process);
    }

    void run() {
      int current_time = 0;
      Process* current_process = NULL;
      do {
        loadprocess(current_time);
        if(!current_process && !processes_stack.empty()) {
          current_process = processes_stack.top();
          processes_stack.pop();
        }
        if(current_process && current_process->T > 0) {
          std::cout << current_process->PID << ": " << current_process->T << std::endl;
          current_process->T--;
        } else if(current_process && current_process->T == 0) {
          current_process = NULL;
        }
        current_time++; 
      } while(current_process || !processes_stack.empty());  
    }

    ~ProcessScheduling() {
      for (Process* p : processes) {
        delete p;
      }
    }
};

int main() {
  int N;
  std::cin >> N;
  ProcessScheduling cpu;

  for (int i = 0; i < N; i++) {
    auto* P = new Process;
    std::cin >> P->PID >> P->A >> P->T;
    cpu.arrive(P);
  }

  cpu.run();
  return 0;
}
