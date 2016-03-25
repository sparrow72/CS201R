#include "ThreeBlanks.hpp"

#include <iostream>
using namespace std;

void ThreeBlanks::CreateQuestion() {
	cout << "Please enter the question below: " << endl;
	cin.ignore();
	getline(cin, m_question);
	cout << endl;
	cout << "Enter the 3 answers" << endl;
	cout << "A1. ";
	cin.ignore();
	getline(cin, m_a1);
	cout << endl;
	cout << "A2. ";
	cin.ignore();
	getline(cin, m_a2);
	cout << endl;
	cout << "A3. ";
	cin.ignore();
	getline(cin, m_a3);
	cout << endl;
}

void ThreeBlanks::Display() {
	cout << m_question;
}

bool ThreeBlanks::Answer() {
	cout << "Provide each question below." << endl;
	cout << "A1. ";
	cin.ignore();
	getline(cin, m_r1);
	cout << endl;
	cout << "A2. ";
	cin.ignore();
	getline(cin, m_r2);
	cout << endl;
	cout << "A3. ";
	cin.ignore();
	getline(cin, m_r3);
	cout << endl;

	cout << "ANSWERED: '" << m_r1 << "', '" << m_r2 << "', '" << m_r3 << "'." << endl;
	cout << "CORRECT : '" << m_a1 << "', '" << m_a2 << "', '" << m_a3 << "'." << endl;

	if (m_a1 != m_r1) {
		return false;
	}
	else if (m_a2 != m_r2) {
		return false;
	}
	else if (m_a3 != m_r2) {
		return false;
	}
	else {
		return true;
	}
}
