#include <iostream>
#include <stack>
#include <vector>
#include <string>

struct Process {
  std::string PID;
  int A, T;
};

class ProcessScheduling {
  private:
    std::vector<Process*> processes;
    std::stack<Process*> processes_stack;

  public:
    void arrive(Process* new_process) {
      processes.push_back(new_process);
    }

    void run() {
      int current_time = 0;
      int index = 0;
      Process* current_process = nullptr;

      while (index < processes.size() || current_process || !processes_stack.empty()) {
        while (index < processes.size() && processes[index]->A == current_time) {
          processes_stack.push(processes[index]);
          index++;
        }
 
        if ((current_process || current_process->T == 0) && !processes_stack.empty()) {
          current_process = processes_stack.top();
          processes_stack.pop();
        }

        if (current_process && current_process->T > 0) {
          std::cout << current_process->PID << ": " << current_process->T << '\n';
          current_process->T--;
        }
        current_time++;
      }
    }

    ~ProcessScheduling() {
      for (auto p : processes) {
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
