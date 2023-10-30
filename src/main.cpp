#include <Arduino.h>
#include <Servo.h>

Servo servoX;
Servo servoY;
Servo servoZ;
Servo servoRamie;  // D9

void wGore();
void wDol();
void wPrawo();
void wLewo();
void doPrzodu();
void doTylu();
void otworz();
void zamknij();

#define X 1
#define Y 1
#define Z 1
#define R 1

int sX = 90;
int sY = 90;
int sZ = 90;
int sRamie = 90;

void setup() {
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(9600);

    servoX.attach(11);
    servoY.attach(9);
    servoZ.attach(10);
    servoRamie.attach(5);

    servoX.write(90);
    servoY.write(90);
    servoZ.write(90);
    servoRamie.write(90);
}

void loop() {
    int pY = analogRead(A1);
    int pX = analogRead(A0);
    int lX = analogRead(A3);
    int lY = analogRead(A2);

    if (pY >= 800) {
        wGore();
    } else if (pY <= 300) {
        wDol();
    }

    if (lX >= 800) {
        wPrawo();
    } else if (lX <= 300) {
        wLewo();
    }

    if (lY >= 800) {
        doPrzodu();
    } else if (lY <= 300) {
        doTylu();
    }

    if (pX >= 800) {
        otworz();
    } else if (pX <= 300) {
        zamknij();
    }

    Serial.println("=== Loop ===");
    Serial.print("sX: ");
    Serial.println(sX);
    Serial.print("sY: ");
    Serial.println(sY);
    Serial.print("sZ: ");
    Serial.println(sZ);
    Serial.print("sRamie: ");
    Serial.println(sRamie);

    delay(500);
}

void wGore() {
    sX += X;
    if (sX > 180) {
        sX = 180;
        return;
    }

    servoX.write(sX);
}

void wDol() {
    sX -= X;
    if (sX < 0) {
        sX = 0;
        return;
    }

    servoX.write(sX);
}

void wLewo() {
    sY -= Y;
    if (sY < 0) {
        sY = 0;
        return;
    }

    servoY.write(sY);
}

void wPrawo() {
    sY += Y;
    if (sY > 180) {
        sY = 180;
        return;
    }

    servoY.write(sY);
}

void doPrzodu() {
    sZ += Z;
    if (sZ > 180) {
        sZ = 180;
        return;
    }

    servoZ.write(sZ);
}

void doTylu() {
    sZ -= Z;
    if (sZ < 0) {
        sZ = 0;
        return;
    }

    servoZ.write(sZ);
}

void otworz() {
    sRamie += R;
    if (sRamie > 180) {
        sRamie = 180;
        return;
    }

    servoRamie.write(sRamie);
}

void zamknij() {
    sRamie -= R;
    if (sRamie < 0) {
        sRamie = 0;
        return;
    }

    servoRamie.write(sRamie);
}