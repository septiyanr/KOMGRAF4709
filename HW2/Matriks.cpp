#include <iostream>
#include <vector>

std::vector<std::vector<int>> tambahMatriks(const std::vector<std::vector<int>>& matriks1, const std::vector<std::vector<int>>& matriks2) {
    int baris = matriks1.size();
    int kolom = matriks1[0].size();

    std::vector<std::vector<int>> hasil(baris, std::vector<int>(kolom, 0));

    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j) {
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
        }
    }

    return hasil;
}

std::vector<std::vector<int>> kurangMatriks(const std::vector<std::vector<int>>& matriks1, const std::vector<std::vector<int>>& matriks2) {
    int baris = matriks1.size();
    int kolom = matriks1[0].size();

    std::vector<std::vector<int>> hasil(baris, std::vector<int>(kolom, 0));

    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j) {
            hasil[i][j] = matriks1[i][j] - matriks2[i][j];
        }
    }

    return hasil;
}

std::vector<std::vector<int>> kaliMatriks(const std::vector<std::vector<int>>& matriks1, const std::vector<std::vector<int>>& matriks2) {
    int baris1 = matriks1.size();
    int kolom1 = matriks1[0].size();
    int kolom2 = matriks2[0].size();

    std::vector<std::vector<int>> hasil(baris1, std::vector<int>(kolom2, 0));

    for (int i = 0; i < baris1; ++i) {
        for (int j = 0; j < kolom2; ++j) {
            for (int k = 0; k < kolom1; ++k) {
                hasil[i][j] += matriks1[i][k] * matriks2[k][j];
            }
        }
    }

    return hasil;
}

void cetakMatriks(const std::vector<std::vector<int>>& matriks) {
    int baris = matriks.size();
    int kolom = matriks[0].size();

    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j) {
            std::cout << matriks[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::vector<int>> matriks1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> matriks2 = {{5, 6}, {7, 8}};

    std::cout << "Matriks 1:\n";
    cetakMatriks(matriks1);

    std::cout << "Matriks 2:\n";
    cetakMatriks(matriks2);

    std::cout << "Hasil penjumlahan matriks:\n";
    auto hasilTambah = tambahMatriks(matriks1, matriks2);
    cetakMatriks(hasilTambah);

    std::cout << "Hasil pengurangan matriks:\n";
    auto hasilKurang = kurangMatriks(matriks1, matriks2);
    cetakMatriks(hasilKurang);

    std::cout << "Hasil perkalian matriks:\n";
    auto hasilKali = kaliMatriks(matriks1, matriks2);
    cetakMatriks(hasilKali);

    return 0;
}
