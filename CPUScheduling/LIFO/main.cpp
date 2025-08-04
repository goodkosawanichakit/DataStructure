#include <iostream>
#include <stack>
#include <vector>
#include <string>

typedef struct process {
  std::string PID;
  int A, T;
} Process;

class ProcessScheduling {
  private:
    std::vector<Process> processes;
    std::stack<Process> processes_stack;
    
  public:
    void arrive(Process new_process) {
      processes.push_back(new_process);
    }

    void run() {
      int current_time = 0;
      int index = 0;
      bool has_current_process = false;
      Process current_process;
      do {
        while(index < processes.size() && processes[index].A == current_time) {
          processes_stack.push(processes[index]);
          index++;
        }
        if((!has_current_process || current_process.T == 0) && !processes_stack.empty()) {
          current_process = processes_stack.top();
          processes_stack.pop();
          has_current_process = true;
        }
        if(has_current_process && current_process.T > 0) {
          std::cout << current_process.PID << ": " << current_process.T << '\n';
        }
        current_process.T--;
        current_time++; 
      } while (index < processes.size() || has_current_process || !processes_stack.empty());
    }
};

int main() {
  int N, A, T;
  std::string PID;
  ProcessScheduling cpu;
  std::cin >> N;

  for(int i = 0; i < N; i++) {
    Process P;
    std::cin >> P.PID >> P.A >> P.T;
    cpu.arrive(P);
  }
  
  cpu.run();
  return 0;
}