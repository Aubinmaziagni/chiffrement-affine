#include <iostream>
#include <string>

// Fonction pour calculer le PGCD (Plus Grand Commun Diviseur)
int pgcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Fonction pour trouver l'inverse multiplicatif modulo m
int inverseModulo(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1; // L'inverse multiplicatif n'existe pas
}

// Fonction pour chiffrer une lettre selon le chiffrement affine
char chiffrementAffine(char lettre, int a, int b) {
    if (isalpha(lettre)) {
        char base = isupper(lettre) ? 'A' : 'a';
        return (a * (lettre - base) + b) % 26 + base;
    }
    return lettre; // Si ce n'est pas une lettre, on le laisse inchangé
}

// Fonction pour chiffrer une chaîne de caractères avec le chiffrement affine
std::string chiffrementAffineString(const std::string &message, int a, int b) {
    std::string chiffre = "";
    for (char lettre : message) {
        chiffre += chiffrementAffine(lettre, a, b);
    }
    return chiffre;
}

int main() {
    // Clé du chiffrement affine (a et b)
    int a, b;

    // Demander à l'utilisateur de saisir les valeurs de la clé
    std::cout << "Entrez la valeur de a (premier paramètre) : ";
    std::cin >> a;
    std::cout << "Entrez la valeur de b (deuxième paramètre) : ";
    std::cin >> b;

    // Vérifier si la valeur de "a" est acceptable (PGCD(a, 26) doit être égal à 1)
    if (pgcd(a, 26) != 1) {
        std::cerr << "La valeur de 'a' n'est pas acceptable. Choisissez une autre valeur.\n";
        return 1;
    }

    // Saisir le message à chiffrer
    std::string message;
    std::cout << "Entrez le message à chiffrer (y compris les espaces) : ";
    std::cin.ignore(); // Pour éviter les problèmes avec getline après cin >>
    std::getline(std::cin, message);

    // Chiffrer le message
    std::string messageChiffre = chiffrementAffineString(message, a, b);

    // Afficher le message chiffré
    std::cout << "Message chiffré : " << messageChiffre << std::endl;

    return 0;
}
