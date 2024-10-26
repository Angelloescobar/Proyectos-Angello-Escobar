void registroEstudiantes() {
    Estudiante nuevoEstudiante;
    nuevoEstudiante.codigo = generarCodigo();
    
    cout << "Ingrese el nombre del estudiante: ";
    cin.ignore();
    getline(cin, nuevoEstudiante.nombre);
    
    cout << "Ingrese los apellidos del estudiante: ";
    getline(cin, nuevoEstudiante.apellido);  
    
    mostrarCarrera(nuevoEstudiante);
    
    cout << "Ingrese la direccion :" << endl;
    mostrarDyM(nuevoEstudiante);
    
    ingresarTelefono(nuevoEstudiante);
    
    cout << "Ingrese su fecha de nacimiento (DD MM AAAA): ";
    cin >> nuevoEstudiante.diaNacimiento >> nuevoEstudiante.mesNacimiento >> nuevoEstudiante.anioNacimiento;
     calcularEdad(nuevoEstudiante);
	 
	 cout << "Fecha de nacimiento ingresada: " 
         << nuevoEstudiante.diaNacimiento << "/" 
         << nuevoEstudiante.mesNacimiento << "/" 
         << nuevoEstudiante.anioNacimiento <<endl;
    cout << "Edad: " << nuevoEstudiante.edad << " anios." << endl;
    
    cout << "Ingrese su correo electronico : ";
    cin >> nuevoEstudiante.correo;
    
    cout << "-------------------------------------\n";
            
    estudiantes.push_back(nuevoEstudiante);
}

void mostrarCarrera(Estudiante &nuevoEstudiante){
		cout <<endl;
		for (size_t i = 0; i < Carreras.size(); i++) {
        cout << i + 1 << ". " << Carreras[i] << endl;
    }
    void mostrarDyM(Estudiante &nuevoEstudiante) {
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
            cout << "Entrada no valida. Por favor, ingrese un numero.\n";
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
                cout << "Entrada no valida. Por favor, ingrese un numero.\n";
                continue;
            }

            if (muniIndice > 0 && muniIndice < departamentos[dptoIndice - 1].size()) {
                nuevoEstudiante.municipio = departamentos[dptoIndice - 1][muniIndice];
                break; 
            } else {
                cout << "Indice de municipio no valido.\n";
            }
        } else {
            cout << "Indice de departamento no valido.\n";
        }
    }