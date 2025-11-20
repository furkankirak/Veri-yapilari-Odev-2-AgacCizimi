# Veri Yapıları Ödevi - Ağaç Çizimi


## Genel Bakış


Bu C++ projesi, temel veri yapılarını (bağlı liste ve ikili arama ağaçları) uygular ve görselleştirir. Uygulama, bir dosyadan karakter dizilerini okur, her dizi için bir ikili arama ağacı (`Agac`) oluşturur ve bu ağaçları özel olarak oluşturulmuş bir bağlı listeye (`BagliListe`) kaydeder. Kullanıcının ağaç listesinde gezinmesine, yapılarını görsel olarak görüntülemesine ve yansıtma ve silme gibi işlemleri gerçekleştirmesine olanak tanıyan konsol tabanlı bir arayüze sahiptir.


## Özellikler


-   **Veriye Dayalı Ağaç Oluşturma:** `agaclar.txt` dosyasında sağlanan karakter dizilerinden ikili arama ağaçları oluşturur.

-   **Ağaçların Bağlı Listesi:** Oluşturulan her ağacı özel bir bağlı listenin düğümünde (`Dugum`) saklar.

-   **Etkileşimli Konsol Kullanıcı Arayüzü:**

-   Bağlı listeyi, düğüm bellek adresleri ve her ağaç için hesaplanan değerlerle birlikte görüntüler.

-   Bağlı listeyi, sayfalandırılmış gruplar halinde (ekran başına 10 düğüm) gezinebilir.

-   Bir gösterge (`^^^^^^^^`) şu anda seçili olan ağacı vurgular.

- **Görsel Ağaç Oluşturma:** Seçilen ikili arama ağacının yapısını, noktalarla temsil edilen düğümler ve dallar dahil olmak üzere, seviye sırası geçme algoritması kullanarak konsolda grafiksel olarak görüntüler.

- **Ağaç İşlemleri:**

- **Ayna (`aynalama`):** Tüm düğümlerinin sol ve sağ alt düğümlerini değiştirerek ağacı ters çevirir.

- **Silme (`cikar`):** Bağlı listeden bir ağacı (ve ilgili düğümü) kaldırır.

## Uygulanan Veri Yapıları


-   **`BagliListe` (Bağlı Liste):** Her düğümün (`Dugum`) bir `Agac` nesnesine işaretçi tuttuğu tek yönlü bağlı liste.

-   **`Agac` (İkili Arama Ağacı):** Karakter verileri için standart bir ikili arama ağacı uygulaması. Ekleme, yükseklik hesaplama ve düğümlerinin ASCII değerlerinin ağırlıklı toplamını hesaplayan bir `veriHesapla` işlevi içerir.

-   **`Kuyruk` (Kuyruk):** Ağaçları görsel olarak görüntülemek için gereken Level order sıralamasını kolaylaştırmak için kullanılan basit bir kuyruk uygulaması (`FIFO`).
## Oluşturma ve Çalıştırma


Bu proje, Unix benzeri bir sistemde kolay derleme ve yürütme için bir `makefile` kullanır.


### Ön Koşullar


-   Bir C++ derleyicisi (örneğin, `g++`,`MinGW`).



### Derleme ve Bağlantı


Deponun kök dizinine gidin ve aşağıdaki komutu çalıştırarak kaynak kodunu derleyin ve nesne dosyalarını bir yürütülebilir dosyaya bağlayın:

Linux için derleme

```bash

make

```

Windows için derleme

```cmd

mingw32-make

```



## Kullanım


Uygulama çalışmaya başladığında, programla etkileşim kurmak için aşağıdaki tuşları kullanın:


| Key | Action                                                      |
|-----|-------------------------------------------------------------|
| `d` | Listedeki **sonraki** ağaca gidin (sağa hareket edin).    |
| `a` | Listedeki **önceki** ağaca git (sola git).  |
| `w` | Seçili ağacı **yansıt**.                      |
| `s` | Seçili ağacı bağlı listeden **sil**.|
| `x` | Uygulamadan **çık**                                   |
