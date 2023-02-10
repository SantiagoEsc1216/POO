#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Alumno{
private:
    string nombre, examen;
    int asistencia;
    vector<float>calificaciones;
    vector<float>promedio;

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

    void set_cal(float cal){
        this->calificaciones.push_back(cal);
    }

    float get_cal(int parcial){
        return this->calificaciones[parcial];
    }
};

class Grupo{
private:
    vector<Alumno> alumnos;
    string nombre;
    int tam, parciales, parcial_actual;
public:

    Grupo(){
        this->parcial_actual = 1;
    }

    void crear_grupo(){
        string nombre_alumno;
        cout<<"Nombre del grupo: ";
        cin>> this->nombre;
        cout<<"Cantidad de parciales: ";
        cin>> parciales;

        cout<<"Ingresar numero de alumnos: ";
        cin>>tam;
        for(int i = 0; i < tam; i++){
            cout<<"Ingresar nombre del alumno "<<i+1<<": ";
            cin >> nombre_alumno;
            Alumno alumno = Alumno(nombre_alumno);
            alumnos.push_back(alumno);
        }

    }

    void tomar_asistencia(){
        cout<<"Toma de asistencia (1.Presente 0.Ausente)"<<endl;
        for(int i = 0; i < tam; i++){
            int presente;
            cout<<alumnos[i].get_nombre()<<" presente?: ";
            cin>> presente;

            if(presente){
                alumnos[i].set_asistencia();
            }
        }
    }

    void calificar(){
        int cal;
        if(this->parcial_actual <= this->parciales){
            for(int i = 0; i<tam; i++){
                cout<<"Parcial: "<<this->parcial_actual<<endl;
                cout<<"Calificacion de "<<alumnos[i].get_nombre()<<": ";
                cin>>cal;
                alumnos[i].set_cal(cal);
            }
            this->parcial_actual++;
        }else{
            //Extraordinario o titulo
        }

    }

    void imprimir_grupo(){
        for(int i = 0; i < tam; i++){
            cout<<alumnos[i].get_nombre()<<": "<<alumnos[i].get_asistencia()<<endl;
            cout<<"Calificaciones: ";
            for(int j = 1; j < this->parcial_actual; j++ ){
                cout<<alumnos[i].get_cal(j)<<" | ";
            }
            cout<<endl;
        }
    }
};



int main() {

    Grupo grupo;
    grupo.crear_grupo();
    grupo.tomar_asistencia();
    grupo.calificar();
    grupo.imprimir_grupo();
    grupo.calificar();
    grupo.imprimir_grupo();
}

