#include "Triangle.h"
#include <iostream>

using namespace std;

LStack::LStack() {
    topNode = nullptr;
}

LStack::~LStack() {
    // Libera la memoria de todos los nodos en la pila
    while (topNode != nullptr) {
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
}

void LStack::Push(int value) {
    // Agrega un nuevo nodo con el valor especificado en el tope de la pila
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = topNode;
    topNode = newNode;
}

void LStack::Pop() {
    // Remueve el nodo en el tope de la pila
    if (IsEmpty()) {
        cout << "Error: Stack is empty." << endl;
        return;
    }

    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
}

int LStack::Top() {
    // Retorna el valor almacenado en el tope de la pila
    if (IsEmpty()) {
        cout << "Error: Stack is empty." << endl;
        return -1; // Retorna un valor predeterminado
    }

    return topNode->data;
}

bool LStack::IsEmpty() {
    // Verifica si la pila está vacía
    return topNode == nullptr;
}

LQueue::LQueue() {
    frontNode = nullptr;
    backNode = nullptr;
}

LQueue::~LQueue() {
    // Libera la memoria de todos los nodos en la cola
    while (frontNode != nullptr) {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
    }
}

void LQueue::Enqueue(int value) {
    // Agrega un nuevo nodo con el valor especificado al final de la cola
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (IsEmpty()) {
        frontNode = newNode;
        backNode = newNode;
    }
    else {
        backNode->next = newNode;
        backNode = newNode;
    }
}

void LQueue::Dequeue() {
    // Remueve el nodo al frente de la cola
    if (IsEmpty()) {
        cout << "Error: Queue is empty." << endl;
        return;
    }

    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;

    if (frontNode == nullptr) {
        backNode = nullptr;
    }
}

int LQueue::Front() {
    // Retorna el valor almacenado en el frente de la cola
    if (IsEmpty()) {
        cout << "Error: Queue is empty." << endl;
        return -1; // Retorna un valor predeterminado
    }

    return frontNode->data;
}

int LQueue::Back() {
    // Retorna el valor almacenado al final de la cola
    if (IsEmpty()) {
        cout << "Error: Queue is empty." << endl;
        return -1; // Retorna un valor predeterminado
    }

    return backNode->data;
}

bool LQueue::IsEmpty() {
    // Verifica si la cola está vacía
    return frontNode == nullptr;
}

Triage::Triage() {
    // Inicializa las colas de urgencia
    for (int i = 0; i < 5; i++) {
        urgencyQueues[i] = LQueue();
    }
}

void Triage::AddPatient(int urgency, string patient_name) {
    if (urgency < 1 || urgency > 5) {
        cout << "Error: Invalid urgency level." << endl;
        return;
    }

    // Agrega al paciente al final de la cola correspondiente al nivel de urgencia
    urgencyQueues[urgency - 1].Enqueue(urgency);
    cout << "Patient " << patient_name << " added to urgency level " << urgency << "." << endl;
}

void Triage::PassPatient() {
    // Pasa al siguiente paciente de acuerdo al nivel de urgencia más bajo
    for (int i = 0; i < 5; i++) {
        if (!urgencyQueues[i].IsEmpty()) {
            int patientUrgency = urgencyQueues[i].Front();
            urgencyQueues[i].Dequeue();
            cout << "Patient with urgency level " << patientUrgency << " passed to the next stage." << endl;
            return;
        }
    }

    cout << "No patients to pass." << endl;
}

void Triage::Print() {
    // Imprime los nombres de los pacientes en cada nivel de urgencia
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << "-> ";

        if (urgencyQueues[i].IsEmpty()) {
            cout << endl;
            continue;
        }

        LQueue tempQueue = urgencyQueues[i];
        while (!tempQueue.IsEmpty()) {
            cout << tempQueue.Front() << ", ";
            tempQueue.Dequeue();
        }
        cout << endl;
    }
}
