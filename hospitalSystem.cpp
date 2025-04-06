#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

//Structure to hold patient information
struct Patient {
	string cardNumber;
	string name;
	string occupation;
	vector<string> symptoms;
};

// Function to display symptoms list
void displaySymptoms() {
	cout << "Please select at least three symptoms list:\n";
	cout << "1. Fever\n2. Headache\n3. Nausea\n4. Cough\n5. Fatigue\n6. Body aches\n";
	cout << "7. Sore throat\n8. Shortness of breath\n9. Loss of appetite'n10. Runny nose\n";
}

//Function to get a valid integer input from the user (1-10)
int getIntInput() {
	int num;
	while (true) {
		cin >> num;
		if (!cin.fail() && num >= 1 && num <= 10) {
			return num;
		}else {
			cout << "Invalid input. Please enter a number between 1 and 10: ";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
}

//Function to convert symptom number to text
string getSymptomByNumber(int num) {
	switch (num) {
		case 1: return "Fever";
		case 2: return "Headache";
		case 3: return "Nausea";
		case 4: return "Cough";
		case 5: return "Fatigue";
		case 6: return "Body aches";
		case 7: return "Sore throat";
		case 8: return "Shortness of breath";
		case 9: return "Loss of appetite";
		case 10: return "Runny nose";
		default: return "Unknown";
	}
}

//Function to get patient details and selected symptoms
Patient getPatientDetails() {
	Patient patient;
	cout << "Enter your Patient Card Number: ";
	getline(cin, patient.cardNumber);
	
	cout << "Enter your Name: ";
	getline(cin, patient.name);
	
	cout << "Enter your Occupation: ";
	getline(cin, patient.occupation);
	
	displaySymptoms();
	set<int> selectedNumbers;
	
	while (selectedNumbers.size() < 3) {
		cout << " Select a symptom by entering the number (1-10): ";
		int symptomNumber = getIntInput();
		if (selectedNumbers.find(symptomNumber) != selectedNumbers.end())
		{
	cout << "You already selected that symptom. Please choose a different one.\n";
		} else {
			selectedNumbers.insert(symptomNumber);
			patient.symptoms.push_back(getSymptomByNumber(symptomNumber));
		}
	} 
	
	return patient;
}

// Function to diagnose the ailment
string diagnoseAilment(const vector<string>& symptoms) {
	bool hasFever = false, hasCough = false, hasFatigue = false;
	bool hasHeadache = false, hasNausea = false;
	bool hasBreath = false;
	
	for (const auto& symptom: symptoms) {
	    if (symptom == "Fever") hasFever = true;
	    if (symptom == "Cough") hasCough = true;
	    if (symptom == "Fatigue") hasFatigue = true;
	    if (symptom == "Headache") hasHeadache = true;
	    if (symptom == "Nausea") hasNausea = true;
	    if (symptom == "Shortness of breath") hasBreath = true;
}

    if (hasFever && hasCough && hasFatigue)
        return "Common Cold";
    else if (hasFever && hasHeadache && hasNausea)
    	return "Flu";
    else if (hasBreath && hasCough && hasFatigue)
    	return "Possible COVID-19";
    else if (hasHeadache && hasFatigue)
        return "Migraine";
    else
        return "Unknown Ailment";
}

//Function to provide a prescrip
string prescribeMedication(const string& ailment) {
	if (ailment == "Common Cold")
		return "Rest, hydration, and over-the-counter cold medication.";
	else if (ailment == "Flu")
		return "Rest, hydration, and anti-viral medication as prescribed by a doctor.";
	else if (ailment == "Possible COVID-19")
		return "Seek immediate medical attention for COVID-19 testing and care.";
	else if (ailment == "Migraine")
		return "Pain relievers such as ibrufen, and rest in a quiet environment.";
	else
		return "Consult a doctor for further investigation.";
}

//Main function
int main() {
	cout << "-----Kay Klinic PATIENT DIAGNOSIS SYSTEM ----\n\n";
	Patient patient = getPatientDetails();
	string ailment = diagnoseAilment(patient.symptoms);
	string prescription = prescribeMedication(ailment);
	
	cout << "\n--- Detailed Report ---\n";
	cout << "Patient Card Number: " << patient.cardNumber << "\n";
	cout << "Patient Name: " << patient.name << "\n";
	cout << "Patient Occupation: " << patient.occupation << "\n";
	cout << "Symptoms Selected: ";
	for (size_t i = 0; i < patient.symptoms.size(); ++i) {
		cout << patient.symptoms[i];
		if (i < patient.symptoms.size() -1) cout << ", ";
	}   
	cout << "\nDiagnosis: " << ailment << "\n";
	cout << "Prescription: " << prescription << "\n";
	
	return 0;
}