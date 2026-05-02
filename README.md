# Komputasi Numerik Praktikum1

|    NRP     |           Nama             |
| :--------: |       :------------:       |
| 5025251045 | Khalisya Zahra Putria Rahman               |
| 5025251063 | Lina Mushlihah                    |

## Regula Falsi Method (Komputasi Numerik)

Program ini mengimplementasikan metode **Regula Falsi (False Position)** untuk mencari akar persamaan non-linear:

f(x) = e^(-x) - x

---

### Tujuan

Menentukan nilai akar dari fungsi dengan pendekatan numerik menggunakan:

* Metode Regula Falsi
* Visualisasi grafik

---

### Fitur Program

* Iterasi metode Regula Falsi hingga memenuhi toleransi
* Menampilkan proses iterasi (xt dan f(xt))
* Menampilkan hasil akar pendekatan
* Visualisasi grafik menggunakan:

  *  GNUPlot (grafik aktual)
  *  ASCII Graph (visualisasi berbasis grid)

---

### Metode yang Digunakan

Metode Regula Falsi menggunakan interpolasi linear:

xt = (a·f(b) - b·f(a)) / (f(b) - f(a))

Iterasi dilakukan sampai nilai |f(xt)| < toleransi.

---

Program ini menunjukkan bagaimana metode numerik dapat digunakan untuk mencari akar persamaan, serta bagaimana hasilnya dapat divisualisasikan baik secara grafis maupun tekstual.
