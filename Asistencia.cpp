#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Alumno{
private:
    string nombre, examen;
    int asistencia;

public:
    Alumno(string &_nombre){
        nombre = _nombre;
        asistencia = 0;
        examen = "Pendiente";
    }

    void set_asistencia(){
        asistencia++;
    }

    string get_nombre(){
        return nombre;
    }
    int get_asistencia(){
        return asistencia;
    }
};

class Grupo{
private:
    vector<Alumno> alumnos;
    int tam;
public:
    void crear_grupo(){
        string nombre;

        cout<<"Ingresar numero de alumnos"<<endl;
        cin>>tam;
        for(int i = 0; i < tam; i++){
            cout<<"Ingresar nombre del alumno "<<i+1<<":";
            cin>>nombre;
            Alumno alumno = Alumno(nombre);
            alumnos.push_back(alumno);

        }
    }

    void tomar_asistencia(){
        cout<<"Toma de asistencia (1.Presente 0.Ausente)"<<endl;
        for(int i = 0; i < tam; i++){
            int presente;
            cout<<alumnos[i].get_nombre()<<" presente?"<<endl;
            cin>> presente;

            if(presente){
                alumnos[i].set_asistencia();
            }
        }
    }
    void imprimir_grupo(){
        for(int i = 0; i < tam; i++){
            cout<<alumnos[i].get_nombre()<<": "<<alumnos[i].get_asistencia()<<endl;
        }
    }
};

int main() {

    Grupo grupo = Grupo();
    grupo.crear_grupo();
    grupo.imprimir_grupo();
    grupo.tomar_asistencia();
    grupo.imprimir_grupo();
}

