#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

struct Estudiante {
    int codigo;
    string nombre;
    string apellido;
    string carrera;
    string direccion;
    string departamento;
    string municipio;
    string telefonoPersonal;
    string telefonoCasa;
    string telefonoEmergencia;
    int diaNacimiento;
    int mesNacimiento;
    int anioNacimiento;
    int edad;
    string correo;
};

vector<Estudiante> estudiantes;
vector<string> Carreras = {"Ingenieria", "Administracion", "Derecho"};
vector<vector<string>> departamentos = {{"Jutiapa", "Ipala", "Agua Blanca"}, {"Chiquimula", "Jalapa", "Zacapa"}};

int generarCodigo() {
    return estudiantes.size() + 1;
}

void ingresarTelefono(Estudiante& nuevoEstudiante) {
    cout << "Ingrese el teléfono personal: ";
    cin >> nuevoEstudiante.telefonoPersonal;

    cout << "Ingrese el teléfono de casa: ";
    cin >> nuevoEstudiante.telefonoCasa;

    cout << "Ingrese el teléfono de emergencia: ";
    cin >> nuevoEstudiante.telefonoEmergencia;
}

void calcularEdad(Estudiante& nuevoEstudiante) {
    int current_year = 2024; 
    nuevoEstudiante.edad = current_year - nuevoEstudiante.anioNacimiento;
}

void mostrarCarrera(Estudiante& nuevoEstudiante) {
    cout << endl;
    for (size_t i = 0; i < Carreras.size(); i++) {
        cout << i + 1 << ". " << Carreras[i] << endl;
    }
    int carreraIndice;
    cout << "Seleccione la carrera: ";
    cin >> carreraIndice;
    nuevoEstudiante.carrera = Carreras[carreraIndice - 1];
}

void mostrarDyM(Estudiante& nuevoEstudiante) {
    int dptoIndice;
    while (true) {
        for (size_t i = 0; i < departamentos.size(); i++) {
            cout << i + 1 << ". " << departamentos[i][0] << endl;
        }
        cout << "Seleccione un departamento: ";
        cin >> dptoIndice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no válida. Por favor, ingrese un número.\n";
            continue;
        }
        if (dptoIndice > 0 && dptoIndice <= departamentos.size()) {
            nuevoEstudiante.departamento = departamentos[dptoIndice - 1][0];
            cout << "\nMunicipios en " << nuevoEstudiante.departamento << ":\n";
            for (size_t i = 1; i < departamentos[dptoIndice - 1].size(); i++) {
                cout << i << ". " << departamentos[dptoIndice - 1][i] << endl;
            }
            int muniIndice;
            cout << "Seleccione un municipio:\n";
            cin >> muniIndice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada no válida. Por favor, ingrese un número.\n";
                continue;
            }
            if (muniIndice > 0 && muniIndice < departamentos[dptoIndice - 1].size()) {
                nuevoEstudiante.municipio = departamentos[dptoIndice - 1][muniIndice];
                break;
            } else {
                cout << "Índice de municipio no válido.\n";
            }
        } else {
            cout << "Índice de departamento no válido.\n";
        }
    }
}

void registroEstudiantes() {
    Estudiante nuevoEstudiante;
    nuevoEstudiante.codigo = generarCodigo();

    cout << "Ingrese el nombre del estudiante: ";
    cin.ignore();
    getline(cin, nuevoEstudiante.nombre);

    cout << "Ingrese los apellidos del estudiante: ";
    getline(cin, nuevoEstudiante.apellido);

    mostrarCarrera(nuevoEstudiante);

    cout << "Ingrese la dirección: ";
    cin.ignore();
    getline(cin, nuevoEstudiante.direccion);

    mostrarDyM(nuevoEstudiante);

    ingresarTelefono(nuevoEstudiante);

    cout << "Ingrese su fecha de nacimiento (DD MM AAAA): ";
    cin >> nuevoEstudiante.diaNacimiento >> nuevoEstudiante.mesNacimiento >> nuevoEstudiante.anioNacimiento;

    calcularEdad(nuevoEstudiante);

    cout << "Fecha de nacimiento ingresada: "
         << nuevoEstudiante.diaNacimiento << "/"
         << nuevoEstudiante.mesNacimiento << "/"
         << nuevoEstudiante.anioNacimiento << endl;
    cout << "Edad: " << nuevoEstudiante.edad << " años." << endl;

    cout << "Ingrese su correo electrónico: ";
    cin >> nuevoEstudiante.correo;

    cout << "-------------------------------------\n";

    estudiantes.push_back(nuevoEstudiante);

    // Guardar en fichero
    ofstream archivo("estudiantes.txt", ios::app);
    if (archivo.is_open()) {
        archivo << nuevoEstudiante.codigo << ","
                << nuevoEstudiante.nombre << ","
                << nuevoEstudiante.apellido << ","
                << nuevoEstudiante.carrera << ","
                << nuevoEstudiante.direccion << ","
                << nuevoEstudiante.departamento << ","
                << nuevoEstudiante.municipio << ","
                << nuevoEstudiante.telefonoPersonal << ","
                << nuevoEstudiante.telefonoCasa << ","
                << nuevoEstudiante.telefonoEmergencia << ","
                << nuevoEstudiante.diaNacimiento << "/"
                << nuevoEstudiante.mesNacimiento << "/"
                << nuevoEstudiante.anioNacimiento << ","
                << nuevoEstudiante.edad << ","
                << nuevoEstudiante.correo << "\n";
        archivo.close();
        cout << "Estudiante guardado en fichero con éxito.\n";
    } else {
        cout << "No se pudo abrir el fichero para guardar los datos.\n";
    }
}

int main() {
    char opcion;
    do {
        registroEstudiantes();
        cout << "¿Desea registrar otro estudiante? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    return 0;
}
