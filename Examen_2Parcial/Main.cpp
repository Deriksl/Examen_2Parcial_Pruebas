#include "Triangle.h"

int main() {
    Triage myTriage = Triage();

    // Agrega pacientes al triage con diferentes niveles de urgencia
    myTriage.AddPatient(1, "Pablo");
    myTriage.AddPatient(5, "Maria");
    myTriage.AddPatient(3, "Luis");
    myTriage.AddPatient(2, "Pancho");
    myTriage.AddPatient(1, "Juan");
    myTriage.AddPatient(4, "Pepe");
    myTriage.AddPatient(5, "Ana");
    myTriage.AddPatient(1, "Pedro");

    // Pasa al siguiente paciente
    myTriage.PassPatient();
    myTriage.PassPatient();

    // Imprime la lista de pacientes en cada nivel de urgencia
    myTriage.Print();

    return 0;
}
