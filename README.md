# Wagony
Program na przedmiot Algorytmy i Struktury Danych

POLECENIE:
Na bocznym torze stoi skład wagonów, który trzeba przygotować do podróży. Przygotowanie polega na uporządkowaniu wagonów 
w kolejności rosnącej na torze prowadzącym do peronu. Każdy wagon posiada numer będący liczbą natrualną z zakresu 1...n, 
gdzie n to liczba wszystkich wagonów. Do dyspozycji mamy jedną, ślepo zakończoną bocznicę. 
Skomplikowany układ zwrotnic powoduje, że możemy wykonywać tylko 3 ruchy:

- przemieszczenie wagonu z toru bocznego na tor prowadzący do peronu
- przemieszczenie wagonu z toru bocznego na bocznicę
- przemieszczenie wagonu z bocznicy na tor prowadzący do peronu
Zanim kolejarze zabiorą się do pracy, chcieliby wiedzieć, czy mają po co zaczynać.

Napisz program sprawdzający, czy dla danego ciągu wagonów, da się je uporządkować w kolejności rosnącej korzystając z jednej bocznicy. 
Uwaga: W zadaniu należy zaimplementować stos korzystając z listy.



Wejście
Pierwszą wprowadzoną liczbą jest n - liczba wagonów do uporządkowania. Następnie podanych będzie n liczb - są no numery kolejnych wagonów.

Wyjście
Program powinien wypisać TAK jeżeli możliwe jest uporządkowanie wagonów, w przeciwnym razie powinien wypisać NIE.

Przykład
Wejście:
3
1 3 2

Wyjście:
TAK

Wejście:
4
4 2 3 1

Wyjście:
NIE
