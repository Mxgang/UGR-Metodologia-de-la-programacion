#include<iostream>

struct Tiempo{
  int horas;
  int minutos;
  int segundos;
};

bool esPosterior(const Tiempo &hora1, const Tiempo &hora2){
  bool es_mayor=false;
  if(hora1.horas > hora2.horas){
    es_mayor=true;
  }
  else if(hora1.horas == hora2.horas){
    if(hora1.minutos > hora2.minutos){
      es_mayor=true;
    }
    else if(hora1.minutos == hora2.minutos){
      if(hora1.segundos > hora2.segundos){
        es_mayor=true;
      }
    }
  }
  return es_mayor;
}

int convertirASegundos(const Tiempo &hora){
  int segundos = 0;

  segundos += (hora.horas * 60 * 60) + (hora.minutos * 60) + hora.segundos;

  return segundos;
}

Tiempo convertirATiempo(int sec){
  Tiempo resultado;

  resultado.horas = (int) (sec/3600);
  resultado.minutos = (int) ((sec - resultado.horas * 3600) / 60);
  resultado.segundos = sec - (resultado.horas * 3600 + resultado.minutos * 60);

  if(resultado.horas > 23){
    resultado.horas = 23;
    resultado.minutos = 59;
    resultado.segundos = 59;
  }
  return resultado;
}

Tiempo obtenerNuevoTiempo(const Tiempo &hora, int segundos){
  Tiempo resultado;
  resultado = convertirATiempo(convertirASegundos(hora) + segundos);
  return resultado;
}

int main(){
  Tiempo T1,T2,T3;
  T1.horas=2;
  T1.minutos=30;
  T1.segundos=0;
  
  T2.horas=4;
  T2.minutos=55;
  T2.segundos=28;

  T3.horas=23;
  T3.minutos=59;
  T3.segundos=58;

  std::cout << "Vamos a comprobar los resultados de las funciones creadas:\n" <<
               "\tT1: 2:30:00\n\tT2: 4:55:28\n\tT3: 23:59:58\n";
  std::cout << "esPosterior(T2,T1)= " << esPosterior(T1,T2) <<
               "\nesPosterior(T1,T2)= " << esPosterior(T2,T1) <<
               "\nconvertirASegundos(T1)= " << convertirASegundos(T1) <<
               "\nobtenerNuevoTiempo(T1,1234)= " << obtenerNuevoTiempo(T1,1234).horas <<":"<<obtenerNuevoTiempo(T1,1234).minutos <<":"<<obtenerNuevoTiempo(T1,1234).segundos <<
               "\nobtenerNuevoTiempo(T3,1234)= " << obtenerNuevoTiempo(T3,1234).horas <<":"<<obtenerNuevoTiempo(T3,1234).minutos <<":"<<obtenerNuevoTiempo(T3,1234).segundos << "\n";

  return 0;
}