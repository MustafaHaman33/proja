/**
 * @file main.cpp
 * @description İkili agaclari bagli liste icerisinde yonetmek icin bir program.
 * @course MinGW C++ Ortami
 * @assignment odev 1
 * @date 24 Aralik 2024
 * @author Adiniz, E-posta Adresiniz
 */
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include "../include/LinkedList.h"
#include "../include/BinaryTree.h"

using namespace std;

int boslukMiktari = 5;  // Karakterler arasindaki bosluk miktari

// cizgi yazdirma fonksiyonu
void cizgiYaz() {
    for (int i = 0; i < boslukMiktari; i++) {
        cout << " ";
    }
    cout << "******" << endl;
}

// Satir cizme fonksiyonu
void satirCiz() {
    for (int i = 0; i < boslukMiktari; i++) {
        cout << " ";
    }
    cout << "*" << endl;
}

// Deger yazdirma fonksiyonu
void degerYaz(int deger) {
    cout << setw(boslukMiktari) << deger;
}

// Bagli listeyi yazdirma fonksiyonu
void bagliListeYaz(LinkedList& list) {
    satirCiz();
    cout << endl;

    // Listeyi yazdir
    list.display();  // Bu fonksiyon, bagli listede bulunan agaclari yazdirmalidir

    satirCiz();
    cout << endl;

    // Listeyi tekrar yazdir
    list.display();

    satirCiz();
}

// Menu gosterme fonksiyonu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "A - onceki Dugumle Git\n";
    cout << "D - Sonraki Dugumle Git\n";
    cout << "S - Gecerli Dugumu Sil\n";
    cout << "W - Gecerli Agaci Ayna Yap\n";
    cout << "Q - cikis\n";
    cout << "Bir secenek girin: ";
}

int main() {
    
    LinkedList list;  // Agaclari tutacak bagli liste
    string filename = "agaclar.txt";  // Dosya ismi
    ifstream inputFile(filename);  // Dosyayi acma

    // Dosya kontrolü: Dosya acilmazsa hata ver
    if (!inputFile) {
        cerr << "Hata: Dosya acilamadi: " << filename << endl;
        return 1;
    }

    // Dosyadan satir satir okuyarak ikili agac olustur ve listeye ekle
    string line;
    while (getline(inputFile, line)) {
        BinaryTree *tree = new BinaryTree(); // Yeni bir ikili agac olustur
        for (char ch : line) {
            tree->insert(ch);  // Her karakteri ikili agaca ekle
        }
        list.append(tree);  // Agaclari listeye ekle
    }

    inputFile.close();  // Dosyayi kapatma

    char choice;
    do {
        system("cls");  // Ekrani temizle
        bagliListeYaz(list);  // Listeyi yazdir

        displayMenu();  // Menu goster
        cin >> choice;  // Kullanicidan secim al

        switch (choice) {
            case 'A':
                list.movePrev();  // onceki dugume git
                break;
            case 'D':
                list.moveNext();  // Sonraki dugume git
                break;
            case 'S':
                list.deleteCurrent();  // Gecerli dugumu sil
                break;
            case 'W':
                list.mirrorCurrentTree();  // Gecerli agaci aynalama
                break;
            case 'Q':
                cout << "Programdan cikiliyor." << endl;  // cikis
                break;
            default:
                cout << "Gecersiz secenek. Tekrar deneyin." << endl;
        }
    } while (choice != 'Q');  // Kullanici cikana kadar devam et

    return 0;
}
