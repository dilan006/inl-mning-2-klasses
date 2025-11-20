Det är ett C++ program för att simulera och övervaka sensorer med larmhantering och datalagring.


Funktioner

Tre sensorer:    Temperatur, Luftfuktighet och Lufttryck
Statistik:       Beräkna medelvärde, min, max och standardavvikelse
Tröskelregler:   Sätt upp larm som triggas vid över-/underskridning
Filhantering:    Spara och ladda mätdata från fil
Realtidsövervakning: Läs av alla sensorer samtidigt




Menyalternativ

Läs av alla sensorer
Visa statistik för sensor
Visa alla mätvärden
Lägg till tröskelregel
Visa larm
Spara till fil
Ladda från fil
Avsluta



Det här är alla Filer i programmet

sensor.h/cpp - Sensorklasser (Temperature, Humidity, Pressure)
storage.h/cpp - Datalagring och statistik
threshold.h/cpp - Larmsystem med tröskelregler
measurement.h - Datastruktur för mätvärden
utils.h/cpp - Hjälpfunktioner (tidsstämpel)
main.cpp - Huvudprogram med meny
