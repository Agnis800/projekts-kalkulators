#include <iostream>
#include <bits/stdc++.h>

bool checkLuhn(const std::string & cardNo) {

  int nDigits = cardNo.length(); // nosaka ciparu skaitu numurā

  int nSum = 0, isSecond = false;
  for(int i = nDigits - 1; i >= 0; i--) {

    int d = cardNo[i] - '0'; // nosaka [i] ciparu no kartes numura

    if (isSecond == true)
    d = d * 2; //dubulto skaitli

    //pievieno divus ciparus gadījumiem, ja pēc skaitļa
    //dubultošanas rodas divciparu skaitlis
    nSum += d / 10;
    nSum += d % 10;

    isSecond = !isSecond;

  }
  return (nSum % 10 == 0); //pārbauda, vai atlikums rezultātam ir 0. Ja tas nav 0, kartes numurs ir nederīgs.
}

int main() {
  
  std::string cardNo;
  std::cout << "Ievadiet kredītkartes numuru: ";
  std::cin >> cardNo;

  if(checkLuhn(cardNo)) {
      std::cout << "Kredītkartes numurs ir derīgs" << std::endl;
  } else {
      std::cout << "Kredītkartes numurs nav derīgs" << std::endl;
  }


  return 0;
}
