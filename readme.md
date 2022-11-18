
# Veri Yapıları Ödev - 1

SAU 2022-23 Güz dönemi Veri Yapıları dersi 1. Ödevi


## İstenenler 

  * Verilen txt dosyasındaki satırları okuyup her satırın içeriğini ayrı bir SatirListesi double linked listinde saklamak.

  * Heapte oluşturulan SatirListerini YoneticiListesi double linked listinde saklamak.
  
  * YoneticiListesini ve içeriğini ödevde istenen formata uygun bir şekilde konsol ekranına bastırmak.

  * YoneticiListesindeki nodeleri gösterdikleri SatirListerinin ortalamalarına göre sıralamak.

  * Ödevde belirtilen tuşlara belirtilen fonksiyonları atamak (bir ileri, bir geri, node sil, rastgele sil vs.).
  


## Programın İşleyişi

* Heap'te yntLst adında bir YöneticiListesi oluşturulur.
* `yntLst` 'e  `veriler.txt` dosyasından okunan sayılardan oluşturulan SatirListesi türündeki listelerin adresleri data olarak eklenir.
* Program, `yntLst` dolu olduğu sürece kullanıcı `q` tuşuna basana kadar döngüye girer.
* Her döngünün başında `yntLst` sıralanır, seçili sayfadaki nodeler ve seçili nodedeki SatirListesi ödevde istenen formatta ekrana yazdırılır.
* Kullanıcı ödevde belirtilen tuşlarla istediği işlemleri yapar, gerekli koşullar sağlandığında programdan çıkış yapılır.
## Tuşlar


* **z:** bir sonraki nodeyi seçer.
* **c:** bir önceki nodeyi seçer.
* **a:** bir önceki sayfaya geçer.
* **d:** bir sonraki sayfaya geçer.
* **p:** seçili node yönetici listesinden silinir.
* **k(1.):** seçili yönetici listesi nodesinin gösterdiği satır listesinden rastgele bir node seçer.
* **k(2.):** bir önceki basışta seçilen node silinir, ortalamalar ve sıralama yeniden hesaplanır.
* **q:** programdan çıkılır.
## Hazırlayan

- Mustafa Karadeniz G211210066 / 2-A


