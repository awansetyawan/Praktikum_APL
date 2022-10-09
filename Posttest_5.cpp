// Library 
#include<iostream>
using namespace std;

// Struct
struct game{
    string nama, genre;
    int tahun, harga;
};

// Data Elemen Array
int data_game = 0;

// Array Of Struct
game Game[100];

// Prosedur Tambah Data
void tambah_data(){
    cout << "\nMasukkan Nama Game        : "; fflush(stdin);
    getline(cin, Game[data_game].nama);
    cout << "Masukkan Genre Game       : "; fflush(stdin);
    getline(cin, Game[data_game].genre);
    cout << "Masukkan Tahun Rilis Game : "; cin >> Game[data_game].tahun;
    cout << "Masukkan Harga Game       : Rp. "; cin >> Game[data_game].harga;
    data_game++;
}

// Prosedur Ubah Data
void ubah_data(){
    int ubah, no_ubah;
    cout << "\nNomor Berapa Yang Ingin Diubah ?? >> "; cin >> ubah;
    no_ubah = ubah - 1;
    cout << "\nMasukkan Nama Game Yang Baru        : "; fflush(stdin);
    getline(cin, Game[no_ubah].nama);
    cout << "Masukkan Genre Game Yang Baru       : "; fflush(stdin);
    getline(cin, Game[no_ubah].genre);
    cout << "Masukkan Tahun Rilis Game Yang Baru : "; cin >> Game[no_ubah].tahun;
    cout << "Masukkan Harga Game Yang Baru       : Rp. "; cin >> Game[no_ubah].harga;
}

// Prosedur Lihat Data
void lihat_data(){
    for (int i = 0; i < data_game; i++){
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>    | " << i+1 << " |   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl 
             << "Nama Game        : " << Game[i].nama << endl
             << "Genre Game       : " << Game[i].genre << endl
             << "Tahun Rilis Game : " << Game[i].tahun << endl
             << "Harga Game       : Rp. " << Game[i].harga << endl;
    }
}

// Prosedur Hapus Data
void hapus_data(){
    int hapus, no_hapus, i;
    cout << "\nNomor Berapa Yang Ingin Dihapus ?? >> "; cin >> hapus;
    no_hapus = hapus - 1;
    data_game--;
    for(i = no_hapus; i < data_game; i++){
        Game[i] = Game[i+1];
    }
}

// Prosedur Tampilan Menu Utama
void tampilan_menu(){
  cout << "================================================" << endl
       << "|---------------Selamat Datang-----------------|" << endl
       << "|--------Di Data Penjualan Game Online---------|" << endl
       << "================================================" << endl
       << "- Dibuat Oleh Alif Maulana Setyawan" << endl
       << "\n>>> ------------Menu------------ <<<" << endl
       << "1) Tambah Data Penjualan" << endl
       << "2) Lihat Data Penjualan" << endl
       << "3) Ubah Data Penjualan" << endl
       << "4) Hapus Data Penjualan" << endl
       << "5) Urutkan Data (Bubble Sort)" << endl
	   << "6) Urutkan Data (Shell Sort)" << endl
       << "7) Exit" << endl;
}

// Prosedur Tampilan Menu Pengurutan Bubble Sort
void tampilan_pengurutan_bubble(){
  cout << "\n================================================" << endl
       << "|----------------Pengurutan Data---------------|" << endl
       << "|------------------Bubble Sort-----------------|" << endl
       << "================================================" << endl
       << "\n>>> --------Menu-------- <<<" << endl
       << "1) Nama" << endl
       << "2) Genre" << endl
       << "3) Tahun Rilis" << endl
       << "4) Harga" << endl;
}

// Prosedur Tampilan Menu Pengurutan Shell Sort
void tampilan_pengurutan_shellsort(){
  cout << "\n================================================" << endl
       << "|----------------Pengurutan Data---------------|" << endl
       << "|-------------------Shell Sort-----------------|" << endl
       << "================================================" << endl
       << "\n>>> --------Menu-------- <<<" << endl
       << "1) Nama" << endl
       << "2) Genre" << endl
       << "3) Tahun Rilis" << endl
       << "4) Harga" << endl;
}

// Prosedur Pengurutan Metode Bubble Sort
void bubble_sort(){
    game swap;
    int nomor, urut, x, y;
    cout << "\n================================================" << endl
         << "|------------Jenis Pengurutan Data-------------|" << endl
         << "================================================" << endl
         << "\n>>> -----------Menu----------- <<<" << endl
         << "1) Ascending  (Kecil ke Besar)" << endl
         << "2) Descending (Besar ke Kecil)" << endl;
    cout << "\nMasukkan Nomor Menu : "; cin >> urut;
	
	// Bubble Sort Secara Ascending
    if (urut == 1){

        system("cls");
        cout << "<<===========================|Menu Urut Data|===================================>>" << endl;
        tampilan_pengurutan_bubble();
        cout << "\nMasukkan Nomor Menu : "; cin >> nomor;

        // Sorting Nama
        if (nomor == 1){
            for (int x = 0; x < data_game-1; x++){
                    for (int y = 0; y < data_game-1; y++){
                    if (Game[y].nama > Game[y+1].nama){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        // Sorting Genre
        else if (nomor == 2){
            for (int x = 0; x < data_game-1; x++){
                for (int y = 0; y < data_game-1; y++){
                    if (Game[y].genre > Game[y+1].genre){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        // Sorting Tahun
        else if (nomor == 3){
            for (int x = 0; x < data_game-1; x++){
                for (int y = 0; y < data_game-1; y++){
                    if (Game[y].tahun > Game[y+1].tahun){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        // Sorting Harga
        else if (nomor == 4){
            for (int x = 0; x < data_game-1; x++){
                for (int y = 0; y < data_game-1; y++){
                    if (Game[y].harga > Game[y+1].harga){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        else{
            cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl; 
        }

    }

	// Bubble Sort Secara Descending
    else if(urut == 2){

        system("cls");
        cout << "<<===========================|Menu Urut Data|===================================>>" << endl;
        tampilan_pengurutan_bubble();
        cout << "\nMasukkan Nomor Menu : "; cin >> nomor;

        // Sorting Nama
        if (nomor == 1){
            for (int x = 0; x < data_game-1; x++){
                for (int y = 0; y < data_game-1; y++){
                    if (Game[y].nama < Game[y+1].nama){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        // Sorting Genre
        else if (nomor == 2){
            for (int x = 0; x < data_game-1; x++){
                for (int y = 0; y < data_game-1; y++){
                    if (Game[y].genre < Game[y+1].genre){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        // Sorting Tahun
        else if (nomor == 3){
            for (int x = 0; x < data_game-1; x++){
                for (int y = 0; y < data_game-1; y++){
                    if (Game[y].tahun < Game[y+1].tahun){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        // Sorting Harga
        else if (nomor == 4){
            for (int x = 0; x < data_game-1; x++){
                for (int y = 0; y < data_game-1; y++){
                    if (Game[y].harga < Game[y+1].harga){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        else{
            cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl; 
        }
        
    }

    else{
        cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl; 
    }
    
}

// Prosedur Pengurutan Metode Shell Sort
void shell_sort(){
	game temporary;
	int nilai, nomor, urut,  x, y;
	cout << "\n================================================" << endl
         << "|------------Jenis Pengurutan Data-------------|" << endl
         << "================================================" << endl
         << "\n>>> -----------Menu----------- <<<" << endl
         << "1) Ascending  (Kecil ke Besar)" << endl
         << "2) Descending (Besar ke Kecil)" << endl;
    cout << "\nMasukkan Nomor Menu : "; cin >> urut;

	// Shell Sort Secara Ascending
	if (urut == 1){

		system("cls");
        cout << "<<===========================|Menu Urut Data|===================================>>" << endl;
		tampilan_pengurutan_shellsort();
		cout << "\nMasukkan Nomor Menu : "; cin >> nomor;

        // Sorting Nama
		if (nomor == 1){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].nama > temporary.nama; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
		}

        // Sorting Genre
		else if (nomor == 2){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].genre > temporary.genre; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
		}

        // Sorting Tahun
		else if (nomor == 3){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].tahun > temporary.tahun; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
		}

        // Sorting Harga
		else if (nomor == 4){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].harga > temporary.harga; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
		}

		else{
			cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl; 
		}
	}

	// Shell Sort Secara Descending
	else if (urut == 2){

		system("cls");
        cout << "<<===========================|Menu Urut Data|===================================>>" << endl;
		tampilan_pengurutan_shellsort();
		cout << "\nMasukkan Nomor Menu : "; cin >> nomor;

        // Sorting Nama
		if (nomor == 1){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].nama < temporary.nama; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
		}

        // Sorting Genre
		else if (nomor == 2){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].genre < temporary.genre; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
		}

        // Sorting Tahun
		else if (nomor == 3){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].tahun < temporary.tahun; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<]<<<" << endl;

            lihat_data();
		}

        // Sorting Harga
		else if (nomor == 4){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].harga < temporary.harga; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
		}

		else{
			cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl; 
		}
	}

	else{
			cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl;
	}

}

// Prosedur Tampilan Ketika Keluar Dari Program
void keluar() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                            KELUAR PROGRAM                            |" << endl;
    cout << "========================================================================" << endl;
    cout << "| Info: Terima kasih telah menggunakan program dari Awan <3            |" << endl;
    cout << "========================================================================" << endl;
    exit(0);
}

// Program Utama
int main(){
    
    bool akhiri;
    string ulang;
    
    // Perulangan While
    while(akhiri == false){

        system("cls");
        tampilan_menu();
        int pilih;
        cout << "\nMasukkan Nomor Menu : "; cin >> pilih;
        
        // Percabangan Switch
        switch(pilih){
            
            // Kondisi Menambahkan Data
            case 1:
                system("cls");
                cout << "<<==========================|Menu Tambah Data|==================================>>" << endl;
                
                // Panggil Prosedur Tambah data
                tambah_data();

                cout << "\n>>>> DATA TELAH DITAMBAH <<<<" << endl;
                break;
            
            // Kondisi Melihat Data
            case 2:
                system("cls");
                cout << "<<==========================|Menu Lihat Data|===================================>>" << endl;
                if(data_game > 0){

                    // Panggil Prosedur Lihat Data
                    lihat_data();
                }
                else{
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                }
                break;
            
            // Kondisi Mengubah Data
            case 3:
                system("cls");
                cout << "<<===========================|Menu Ubah Data|===================================>>" << endl;
                if(data_game > 0){

                    // Panggil Prosedur Lihat Data
                    lihat_data();

                    // Panggil Prosedur Ubah Data
                    ubah_data();
                    cout << "\n>>>>> DATA TELAH DIUBAH <<<<<" << endl;
                }
                else{
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                }
                break;
            
            // Kondisi Menghapus Data
            case 4:
                system("cls");
                cout << "<<===========================|Menu Hapus Data|==================================>>" << endl;
                if(data_game > 0){

                    // Panggil Prosedur Lihat Data
                    lihat_data();

                    // Panggil Prosedur Hapus Data
                    hapus_data();
                    cout << "\n>>>> DATA TELAH DIHAPUS <<<<" << endl;
                }
                else{
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                }
                break;
            
			// Kondisi Mengurutkan Data Metode Bubble Sort
            case 5:
                system("cls");
                cout << "<<===========================|Menu Urut Data|===================================>>" << endl;
                if(data_game > 0){

                    // Panggila Prosedur Bubble Sort
                    bubble_sort();
                }
                else{
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                }
                break;
			
			// Kondisi Mengurutkan Data Metode Shell Sort
			case 6:
				system("cls");
                cout << "<<===========================|Menu Urut Data|===================================>>" << endl;
                if(data_game > 0){
                    
                    // Panggil Prosedur Shell Sort
                    shell_sort();
                }
                else{
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                }
				break;

            // Kondisi Untuk Keluar Program
            case 7:

                // Panggil Prosedur Keluar
                keluar();
            
            // Kondisi Default
            default:
                cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl; 
        }
        
        // Konfirmasi Kembali ke Menu Utama
        cout << "\nIngin Kembali Ke Menu Utama ?? (y/t) >> "; cin >> ulang;
        cout << endl;

        // Kondisi Penentu Nilai While
        if (ulang == "y" || ulang == "Y"){
            akhiri = false;
        }
        else if (ulang == "t" || ulang == "T"){
            akhiri = true;
        }
        else{
            akhiri = true;
        }
    }

    // Panggil Prosedur Keluar
    keluar();
}