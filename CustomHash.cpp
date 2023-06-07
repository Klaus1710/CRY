#include <iostream>
#include <random>
#include <string>
using namespace std;

int customHash(const std::string& message)
{
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, 65535);
    generator.seed(hash<string>{}(message));
    return distribution(generator);
}
int main()
{
    string message;
    cout << "Enter the message: ";
    getline(cin, message);
    int hashValue = customHash(message);
    cout << "Original Message: " << message << endl;
    cout << "Hash value: " << hashValue << endl;
    string receivedMessage;
    cout << "Enter the received message: ";
    getline(cin, receivedMessage);
    int receivedHashValue = customHash(receivedMessage);
    cout << "Received Message: " << receivedMessage << endl;
    cout << "Received Hash value: " << receivedHashValue << endl;
    if (receivedHashValue == hashValue)
    {
        cout << "Integrity: The message has not been modified." << endl;
    }
    else
    {
        cout << "Integrity: The message has been modified." << endl;
    }
    return 0;
}
