// # include <iostream>
// using namespace std;
// int main(){
//     cout<<"hello khushi"<<endl;
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
//     string modelName = "Llama";
//     int parameters = 1;
//     double temperature = 0.7;
//     bool local = true;
//     cout << "Model: " << modelName << endl;
//     cout << "Parameters: " << parameters << "B" << endl;
//     cout << "Temperature: " << temperature << endl;
//     cout << "Local: " << local << endl;
//     return 0;
// }


// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
//     string name;
//     cout << "Enter your name: ";
//     cin >> name;
//     cout << "Hello " << name << "!" << endl;
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
//     string prompt;
//     cout << "Enter your prompt: ";
//     getline(cin, prompt);
//     cout << "Your prompt is: " << prompt << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main(){
//     string name;
//     cout<<"enter the fullname:"<<endl;
//     cin>>name;
//     cout<<"your full name is:"<<name<<endl;
// }
//  ------------> cin oly read first letter. and that's why we use getline function


// #include <iostream>
// using namespace std;
// int main() {
//     int number;
//     cout << "Enter a number: ";
//     cin >> number;
//     if (number > 0) {
//         cout << "Positive number" << endl;
//     }
//     else if (number < 0) {
//         cout << "Negative number" << endl;
//     }
//     else {
//         cout << "Zero" << endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main() {
//     for (int i = 1; i <= 5; i++) {
//         cout << "Token: " << i << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
//     string prompt = "Explain OpenVINO";
//     cout << "Prompt: " << prompt << endl;
//     cout << "Length: " << prompt.length() << endl;
//     return 0;
// }

// #include <iostream>
// // #include <vector>
// using namespace std;
// int main() {
//     vector<string> devices;
//     devices.push_back("CPU");
//     devices.push_back("GPU");
//     devices.push_back("NPU");
//     cout << "Available devices:" << endl;
//     for (string device : devices) {
//         cout << device << endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
// void sayHello() {
//     cout << "Hello from function!" << endl;
// }
// int main() {
//     sayHello();
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// void greet(string name) {
//     cout << "Hello " << name << "!" << endl;
// }
// int main() {
//     string name;
//     cout << "Enter your name: ";
//     cin >> name;
//     greet(name);
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int add(int a, int b) {
//     return a + b;
// }
// int main() {
//     int result;
//     result = add(10, 20);
//     cout << "Result: " << result << endl;
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// void printWelcome() {
//     cout << "============================" << endl;
//     cout << "    Local LLM Application   " << endl;
//     cout << "============================" << endl;
// }
// string getPrompt() {
//     string prompt;
//     cout << "Enter your prompt: ";
//     getline(cin, prompt);
//     return prompt;
// }
// void printPrompt(string prompt) {
//     cout << endl;
//     cout << "Your prompt:" << endl;
//     cout << prompt << endl;
// }
// int main() {
//     printWelcome();
//     string prompt = getPrompt();
//     printPrompt(prompt);
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// class Model {
// public:
//     string name;
//     string device;
//     void showInfo() {
//         cout << "Model: " << name << endl;
//         cout << "Device: " << device << endl;
//     }
// };
// int main() {
//     Model model;
//     model.name = "Llama";
//     model.device = "CPU";
//     model.showInfo();
//     return 0;
// }

// #include <iostream>
// #include <stdexcept>
// using namespace std;
// void loadModel() {
//     throw runtime_error("Model could not be loaded.");
// }
// int main() {
//     try {
//         loadModel();
//         cout << "Model loaded successfully." << endl;
//     }
//     catch (const exception& error) {
//         cout << "Error: " << error.what() << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;
// int main() {
//     ofstream file("test.txt");
//     file << "OpenVINO Local LLM Project" << endl;
//     file << "C++ file handling test" << endl;
//     file.close();
//     cout << "File created successfully." << endl;
//     return 0;
// }

// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;
// int main() {
//     ifstream file("test.txt");
//     string line;
//     while (getline(file, line)) {
//         cout << line << endl;
//     }
//     file.close();
//     return 0;
// }


// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;
// bool fileExists(string filename) {
//     ifstream file(filename);
//     return file.good();
// }
// int main() {
//     string filename;
//     cout << "Enter filename: ";
//     cin >> filename;
//     if (fileExists(filename)) {
//         cout << "File exists." << endl;
//     }
//     else {
//         cout << "File does not exist." << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// int main(int argc, char* argv[]) {
//     cout << "Number of arguments: " << argc << endl;
//     if (argc > 1) {
//         cout << "Argument 1: " << argv[1] << endl;
//     }
//     else {
//         cout << "No argument provided." << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// void printWelcome() {
//     cout << "=================================" << endl;
//     cout << "       Local LLM Application      " << endl;
//     cout << "=================================" << endl;
// }
// string getPrompt() {
//     string prompt;
//     cout << "Enter your prompt: ";
//     getline(cin, prompt);
//     return prompt;
// }
// void generateFakeResponse(string prompt) {
//     cout << endl;
//     cout << "Prompt received:" << endl;
//     cout << prompt << endl;
//     cout << endl;
//     cout << "Model response:" << endl;
//     cout << "This is a fake response for testing." << endl;
// }
// int main() {
//     printWelcome();
//     string prompt = getPrompt();
//     generateFakeResponse(prompt);
//     return 0;
// }

// #include <openvino/openvino.hpp>
// #include <iostream>
// using namespace std;
// int main() {
//     ov::Core core;
//     cout << "OpenVINO is working!" << endl;
//     cout << "Available devices:" << endl;
//     for (const auto& device : core.get_available_devices()) {
//         cout << device << endl;
//     }
//     return 0;
// }