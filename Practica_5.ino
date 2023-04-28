/*
Fundación Kinal
Centro Educativo Técnico Labral Kinal
Electrónica
Grado: Quinto
Sección: A
Curso: Taller de Electrónica Digital y Reparación de Computadoras I
Nombre: Javier Andre Gonzalez Barrera
Carné: 2019474
*/
int trig = 2;
int echo = 3;
int Buzzer = 5;
int DO = 261;
int RE = 294;
int MI = 329;
int DORE = 349;
int SOL = 392;
int LA = 440;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duracion, distancia;
  duracion = medirDuracionPulso();
  distancia = calcularDistancia(duracion);

  if (distancia > 0 && distancia <= 5) {
    reproducirTono(Buzzer, DO, 500);
  } else if (distancia > 5 && distancia <= 10) {
    reproducirTono(Buzzer, RE, 500);
  } else if (distancia > 10 && distancia <= 15) {
    reproducirTono(Buzzer, MI, 350);
  } else if (distancia > 15 && distancia <= 20) {
    reproducirTono(Buzzer, DORE, 150);
  } else if (distancia > 20 && distancia <= 25) {
    reproducirTono(Buzzer, SOL, 500);
  } else if (distancia > 25 && distancia <= 30) {
    reproducirTono(Buzzer, LA, 350);
  } else {
    detenerTono(Buzzer);
  }

  mostrarDistancia(distancia);
}

long medirDuracionPulso() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  return pulseIn(echo, HIGH);
}

int calcularDistancia(long duracion) {
  return duracion / 58;
}

void reproducirTono(int pin, int frecuencia, int duracion) {
  tone(pin, frecuencia, duracion);
}

void detenerTono(int pin) {
  noTone(pin);
}

void mostrarDistancia(int distancia) {
  Serial.print(distancia);
  Serial.println(" cm");
}
