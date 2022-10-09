#include <iostream> //library input output
#include <windows.h> // library windows
#include <string.h> // library mengenali strlvr(str)
#include <conio.h> // menampilkan hasil antarmuka
#include <unistd.h> // library sleep
#include <ctime>  // library waktu
#include <fstream> // library file
#include <sstream> // library konversi string
#include <limits> // error handling

using namespace std;

struct data_pulsa{ // struct pulsa
	string operator_pulsa;
	int jumlah_pulsa;
	int harga_pulsa;
};

struct data_paket{ // struct paket
	string operator_paket;
	float jumlah_paket;
	int harga_paket;
};

struct data_top_up{ // struct top up
	string operator_top_up;
	int jumlah_top_up;
	int harga_top_up;
};

struct internet_celluler{ // struct utama
	data_pulsa pulsa; // struct dalam struct
	data_paket paket;
	data_top_up top_up;
};

internet_celluler utama[300]; 
int jumlahdata_pulsa = 0; // max 100 untuk setiap jumlah data
int jumlahdata_paket = 0; 
int jumlahdata_top_up = 0; 

// deklarasi file eksternal secara global
fstream pulsa;
fstream paket_internet;
fstream topup;

// Prototype --> saling memanggil prosedur/fungsi
void tagline();
bool eror_handling(int error);
void setcolor(unsigned short color);
void menu_utama();
void menu_pendataan();
void menu_lihatdata();
void menu_sorting();
void menu_searching();
void tampil_dataPulsa();
void DataPulsa();
void tampil_dataPaket();
void DataPaket();
void tampil_dataTop_up();
void DataTopup();
void perpindahan_data(internet_celluler *array1, internet_celluler *array2);
void urutkan_pulsa();
void urutkan_paket();
void urutkan_topup();
string hurufkecil(string huruf);
bool checkkata(string cari, string arrayKata);
int searching_pulsa(int jumlahdata_pulsa);
int searching_paket(int jumlahdata_paket);
int searching_topup(int jumlahdata_top_up);
void tambah_data();
void ubah_data();
void hapus_data();
void keluar();
void file_pulsa();
void file_paket();
void file_topup();
void updatefile_pulsa();
void updatefile_paket();
void updatefile_topup();
void pindah_datapulsa();
void pindah_datapaket();
void pindah_datatopup();

// Fungsi Utama
int main(){
	int pilih_MenuUtama, pilih_menulihat, pilih_MenuSort, pilih_MenuSearch, cek;
	bool akhiri;
    string ulang;
	
	// Perulangan While
    while(akhiri == false){
		system("cls");

		file_pulsa();
		file_paket();
		file_topup();

		tagline();
		sleep(1);
		menu_utama();
		
		// Panggil Eror Handling
		do{
			setcolor(3);
			cout<< "\n--- Pilih Menu : ";  cin >> cek;
			setcolor(7);
		}while(eror_handling(cek) == true);
		pilih_MenuUtama = cek;

		sleep(1);
		switch(pilih_MenuUtama){
			case 1:
				system("cls");
				if(jumlahdata_pulsa == 0){
					pindah_datapulsa();
				}
				if(jumlahdata_paket == 0){
					pindah_datapaket();
				}
				if(jumlahdata_top_up == 0){
					pindah_datatopup();
				}

				tagline(); // rekursif
				tambah_data();
				break;
			
			case 2:
				sleep(1); // jeda 1 detik
				system("cls"); // membersihkan output
				
				tagline();
				if(jumlahdata_pulsa == 0){
					pindah_datapulsa();
				}
				tampil_dataPulsa();
				
				sleep(1);
				
				if(jumlahdata_paket == 0){
					pindah_datapaket();
				}
				tampil_dataPaket();
				
				sleep(1);
				
				if(jumlahdata_top_up == 0){
					pindah_datatopup();
				}
				tampil_dataTop_up();

				sleep(1);
				setcolor(3);
				cout<< "\nTekan 'Enter' untuk lanjut..."; getch(); cout << endl;
				setcolor(7);
				
				sleep(1);
				checkpoin_menulihat:
				system("cls");
				tagline();
				menu_lihatdata();

				// Panggil Eror Handling
				do{
					setcolor(3);
					cout<< "\n--- Pilih Menu : ";  cin >> cek; 
					setcolor(7);
				}while(eror_handling(cek) == true);
				pilih_menulihat = cek;

				if (pilih_menulihat == 1){	
					system("cls");
					tagline();
					menu_pendataan();

					// Panggil Eror Handling
					do{
						setcolor(3);
						cout<< "\n--- Pilih Menu : ";  cin >> cek; 
						setcolor(7);
					}while(eror_handling(cek) == true);
					pilih_MenuSort = cek;
					
					if(pilih_MenuSort == 1){
						system("cls");
						tagline();
						cout << endl;
						
						if(jumlahdata_pulsa > 0){
							urutkan_pulsa();
							sleep(1);
							setcolor(3);
							cout<< "\nTekan 'Enter' untuk lanjut..."; getch(); cout << endl;
							setcolor(7);
						}
						else{
							setcolor(4);
							cout<< "                   DAFTAR PENDATAAN KOSONG!\n" << endl; 
							setcolor(7);
							sleep(3);
						}
						system("cls");
					}

					else if(pilih_MenuSort == 2){
						system("cls");
						tagline();
						cout << endl;
							
						if(jumlahdata_paket > 0){
							urutkan_paket();
							sleep(1);
							setcolor(3);
							cout<< "\nTekan 'Enter' untuk lanjut..."; getch(); cout << endl;
							setcolor(7);
						}
						else{
							setcolor(4);
							cout<< "                   DAFTAR PENDATAAN KOSONG!\n" << endl; 
							setcolor(7);
							sleep(3);
						}
						system("cls");
					}

					else if(pilih_MenuSort == 3){
						system("cls");
						tagline();
						cout << endl;
							
						if(jumlahdata_top_up > 0){
							urutkan_topup();
							sleep(1);
							setcolor(3);
							cout<< "\nTekan 'Enter' untuk lanjut..."; getch(); cout << endl;
							setcolor(7);
						}
						else{
							setcolor(4);
							cout<< "                   DAFTAR PENDATAAN KOSONG!\n" << endl; 
							setcolor(7);
							sleep(3);
						}
						system("cls");
					}

					else if(pilih_MenuSort == 4){
						goto checkpoin_menulihat;
					}

					else{
						sleep(1);
						setcolor(4);
						cout << "\n---- Menu Tidak Tersedia! ----" << endl;
						setcolor(7);
						sleep(1);
						system("cls");
					}
				}
		
				else if(pilih_menulihat == 2){
					system("cls");
					tagline();
					menu_pendataan();

					// Panggil Eror Handling
					do{
						setcolor(3);
						cout<< "\n--- Pilih Menu : ";  cin >> cek;
						setcolor(7);
					}while(eror_handling(cek) == true);
					pilih_MenuSearch = cek; 
					
					if(pilih_MenuSearch == 1){
						system("cls");
						tagline();
						cout << endl;
	
						if(jumlahdata_pulsa > 0){
							searching_pulsa(jumlahdata_pulsa);
							
							setcolor(3);
							cout<< "\nTekan 'Enter' untuk lanjut..."; getch(); cout << endl;
							setcolor(7);
						}
						else{
							setcolor(4);
							cout<< "\n          DAFTAR PENDATAAN KOSONG!" << endl 
								<< "--- Tidak Dapat Melakukan Pencarian Data---" << endl; // kosong jika banyak data < 0
							setcolor(7);
							sleep(3);
						}
						system("cls");
					}

					else if(pilih_MenuSearch == 2){
						system("cls");
						tagline();
						cout << endl;
							
						if(jumlahdata_paket > 0){
							searching_paket(jumlahdata_paket);
							
							setcolor(3);
							cout<< "\nTekan 'Enter' untuk lanjut..."; getch(); cout << endl;
							setcolor(7);
						}
						else{
							setcolor(4);
							cout<< "\n          DAFTAR PENDATAAN KOSONG!" << endl 
								<< "--- Tidak Dapat Melakukan Pencarian Data---" << endl; // kosong jika banyak data < 0
							setcolor(7);
							sleep(3);
						}
						system("cls");
					}

					else if(pilih_MenuSearch == 3){
						system("cls");
						tagline();
						
						cout << endl;
						if(jumlahdata_top_up > 0){
							searching_topup(jumlahdata_top_up);
							
							setcolor(3);
							cout<< "\nTekan 'Enter' untuk lanjut..."; getch(); cout << endl;
							setcolor(7);
						}
						else{
							setcolor(4);
							cout<< "\n          DAFTAR PENDATAAN KOSONG!" << endl 
								<< "--- Tidak Dapat Melakukan Pencarian Data---" << endl; // kosong jika banyak data < 0
							setcolor(7);
							sleep(3);
						}
						system("cls");
					}

					else if(pilih_MenuSearch == 4){
						goto checkpoin_menulihat;
					}

					else{
						sleep(1);
						setcolor(4);
						cout << "\n---- Menu Tidak Tersedia! ----" << endl;
						setcolor(7);
						sleep(1);
						system("cls");
					}
				}
					
				else if(pilih_menulihat == 3){
					main();
				}

				else{
					sleep(1);
					setcolor(4);
					cout << "\n---- Menu Tidak Tersedia! ----" << endl;
					setcolor(7);
					sleep(1);
					system("cls");
				}

				break;
		

			case 3:
				ubah_data();
				break;
			
			
			case 4:
				hapus_data();
				break;

			
			case 5:
				keluar();


			default:
				sleep(1);
				setcolor(4);
				cout << "\n---- Menu Tidak Tersedia! ----" << endl;
				setcolor(7);
				sleep(1);
				system("cls");
		}

		// Konfirmasi Kembali ke Menu Utama
		tagline();
		setcolor(6);
        cout << "\nIngin Kembali Ke Menu Utama ?? [y/t] : "; cin >> ulang;
        setcolor(7);
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

    return 0;
}

void tagline(){
	// tanggal / waktu sekarang berdasarkan sistem saat ini
    time_t now = time(0);
    // ubah sekarang menjadi bentuk string
	char* dt = ctime(&now);
	
	setcolor(24);
 	cout << "____________________________________________________________________________________________________________________________________________________________________________" << endl;
 	setcolor(3);
 	cout << "                                             .  .     ..     ....    .    .. .     ..         ....    ....    .       ." << endl;   
 	cout << "                                             :.:     :..:    :..:    :    : ::    :..:        :       :...    :       :" << endl;
 	cout << "                                             :  :    :  :    :  :    :    : .:    :  :        :...    :...    :...    :..." << endl;
 	cout << endl;
 	setcolor(3);
 	cout << "                                                     S I S T E M  P E N D A T A A N  I N T E R N E T  C E L L U L E R"<< endl;
 	setcolor(8);
 	cout << "                                                                       "<< dt << endl;
 	setcolor(24);
 	cout << "____________________________________________________________________________________________________________________________________________________________________________" << endl;
 	setcolor(7);
}

// Fungsi Error Handling
bool eror_handling(int eror){
    if(cin.fail()){
        cin.clear();
        setcolor(4);
        cout<< "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl
        	<< "---- Masukkan Angka Bukan Huruf ----\n" << endl;
        setcolor(7);

        // Menetapkan jumlah maksimum untuk diabaikan
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    else{
        return false;
    }
    return eror;
}

// Prosedur untuk menentukan warna tampilan
void setcolor(unsigned short color){
	HANDLE hCon = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hCon, color);
}

void menu_utama(){ // Prosedur Tampil Menu Utama
	setcolor(8);
	cout<< endl
		<< "============================================================" << endl
    	<< "||                        MENU UTAMA                      ||" << endl// memiliki 5 menu
    	<< "============================================================" << endl
    	<< "|| [1] Tambah Data Penjualan                              ||" << endl							
    	<< "|| [2] Daftar Data Penjualan                              ||" << endl
    	<< "|| [3] Ubah Data Penjualan                                ||" << endl
    	<< "|| [4] Hapus Data Penjualan                               ||" << endl
    	<< "|| [5] Keluar Program                                     ||" << endl
    	<< "============================================================" << endl;
    setcolor(7);
}

void menu_pendataan(){ // Prosedur Tampil Menu Pendataan
	setcolor(8);
	cout<< endl
		<< "============================================================" << endl 
    	<< "||                     Menu Pendataan                     ||" << endl  // memiliki 4 menu
    	<< "============================================================" << endl 
    	<< "|| [1] Data Pulsa                                         ||" << endl 
    	<< "|| [2] Data Paket Internet                                ||" << endl 
		<< "|| [3] Data Top Up                                        ||" << endl 
    	<< "|| [4] Kembali                                            ||" << endl
    	<< "============================================================" << endl;
    setcolor(7);
}

void menu_lihatdata(){ // Prosedur Tampil Lihat Data
	setcolor(8);
	cout<< endl
		<< "============================================================" << endl
    	<< "||                     Menu Lihat Data                    ||" << endl // memiliki 3 menu
    	<< "============================================================" << endl
    	<< "|| [1] Urutkan Data                                       ||" << endl		
    	<< "|| [2] Cari Data                                          ||" << endl
    	<< "|| [3] Kembali                                            ||" << endl
		<< "============================================================" << endl;	
	setcolor(7);
}


// Prosedur untuk menampilkan dan melihat data
void tampil_dataPulsa(){
	
	setcolor(7);
	cout<< "\n\n                     DAFTAR DATA PENJUALAN                 " << endl
		<< " --------------------------- PULSA ------------------------" << endl
		<< endl;
		
	setcolor(8);

	if (jumlahdata_pulsa > 0){ // banyak data lebih dari 0

		jumlahdata_pulsa = 0;
		pindah_datapulsa();

		DataPulsa();
	}
			
	else {
		setcolor(4);
		cout<< "                    DAFTAR PENDATAAN KOSONG!\n" << endl; // kosong jika banyak data < 0
		setcolor(7);
	}	
}

void DataPulsa(){
	for(int i = 0; i < jumlahdata_pulsa; i++){
		cout<< "                      DATA PULSA KE - " << i + 1 << endl
	    	<< "                      -------------------" << endl
			<< "Operator Pulsa        : " << utama[i].pulsa.operator_pulsa << endl
			<< "Jumlah Pulsa          : " << utama[i].pulsa.jumlah_pulsa << endl
			<< "Harga Pulsa           : Rp. " << utama[i].pulsa.harga_pulsa << endl
			<< endl;
	}
}

void tampil_dataPaket(){
	
	setcolor(7);
	cout<< "\n\n                     DAFTAR DATA PENJUALAN                 " << endl
		 << " ----------------------- PAKET INTERNET ------------------- " << endl
		 << endl;

	setcolor(8);
	if (jumlahdata_paket > 0){ // banyak data lebih dari 0

		jumlahdata_paket = 0;
		pindah_datapaket();

		DataPaket();
	}
	
	else {
		setcolor(4);
		cout<< "                    DAFTAR PENDATAAN KOSONG!\n" << endl; // kosong jika banyak data < 0
		setcolor(7);
	}
}

void DataPaket(){
	for(int i = 0; i < jumlahdata_paket; i++){ // akan tampil sebanyak jumlah data
		cout<< "                      DATA PAKET KE - " << i + 1 << endl
	    	<< "                      -------------------" << endl
			<< "Operator Paket        : " << utama[i].paket.operator_paket << endl
			<< "Jumlah Paket          : " << utama[i].paket.jumlah_paket << endl	
			<< "Harga Paket           : Rp. " << utama[i].paket.harga_paket << endl		
			<< endl;
	}
}

void tampil_dataTop_up(){
	
	setcolor(7);
	cout<< "\n\n                     DAFTAR DATA PENJUALAN                 " << endl
		 << " --------------------------- TOP UP -----------------------" << endl
		 << endl;
		 
	setcolor(8);
	if (jumlahdata_top_up > 0){ // banyak data lebih dari 0

		jumlahdata_top_up = 0;
		pindah_datatopup();

		DataTopup();
	}
	
	else {
		setcolor(4);
		cout<< "                    DAFTAR PENDATAAN KOSONG!\n" << endl; // kosong jika banyak data < 0
		setcolor(7);
	}
			
}

void DataTopup(){
	for(int i = 0; i < jumlahdata_top_up; i++){ // akan tampil sebanyak jumlah data
		cout<< "                      DATA TOP UP KE - " << i + 1 << endl
	    	<< "                      -------------------" << endl
			<< "Operator Top Up       : " << utama[i].top_up.operator_top_up << endl
			<< "Jumlah Top Up         : " << utama[i].top_up.jumlah_top_up << endl
			<< "Harga Top Up          : Rp. " << utama[i].top_up.harga_top_up << endl
			<< endl;
	}
}

// Perpindahan Data Pada Sorting Dengan Menggunakan Parameter Pointer
void perpindahan_data(internet_celluler *array1, internet_celluler *array2){
	internet_celluler dataSementara = *array1;
	*array1 = *array2;
	*array2 = dataSementara;
}

void urutkan_pulsa(){ // Prosedur Urutkan Data Pulsa
    int nomor_pilih, cek;
	bool menukar;
		
	if(jumlahdata_pulsa == 0){
		pindah_datapulsa();
	}

    setcolor(8);
	cout<< endl
		<< "============================================================" << endl
    	<< "||                   Menu Urutkan Data                    ||" << endl
    	<< "============================================================" << endl
    	<< "|| [1] Urutkan Data Menurun                               ||" << endl		
    	<< "|| [2] Urutkan Data Menaik                                ||" << endl
		<< "============================================================" << endl;	
	setcolor(7);
    
    // Panggil Eror Handling
    do{
        setcolor(3);
        cout<< "\n--- Pilih Menu : ";  cin >> cek;
        setcolor(7);
    }while(eror_handling(cek) == true);
    nomor_pilih = cek;

    if(nomor_pilih == 1){
        for (int x = 0; x < jumlahdata_pulsa-1; x++){
            menukar = false;
            for (int y = 0; y < jumlahdata_pulsa-x-1; y++){
                if (utama[y].pulsa.operator_pulsa < utama[y+1].pulsa.operator_pulsa){
                    perpindahan_data(&utama[y], &utama[y+1]);
                    menukar = true;
                }
            }
            if(menukar == false){
                break;
            }
        }

        system("cls");
        tagline();
        cout << endl;
        DataPulsa();
    }
    else if(nomor_pilih == 2){
        for (int x = 0; x < jumlahdata_pulsa-1; x++){
            menukar = false;
            for (int y = 0; y < jumlahdata_pulsa-x-1; y++){
                if (utama[y].pulsa.operator_pulsa > utama[y+1].pulsa.operator_pulsa){
                    perpindahan_data(&utama[y], &utama[y+1]);
                    menukar = true;
                }
            }
            if(menukar == false){
                break;
            }
        }

        system("cls");
        tagline();
        cout << endl;
        DataPulsa();
    }
    else{
        setcolor(4);
        cout << "\n---- Menu Tidak Tersedia! ----" << endl;
        setcolor(7);
    }
}

void urutkan_paket(){ // Prosedur Urutkan Data Paket
	int nomor_pilih, cek;
    bool menukar;
		 
	if(jumlahdata_paket == 0){
		pindah_datapaket();
	}

    setcolor(8);
	cout<< endl
		<< "============================================================" << endl
    	<< "||                   Menu Urutkan Data                    ||" << endl
    	<< "============================================================" << endl
    	<< "|| [1] Urutkan Data Menurun                               ||" << endl		
    	<< "|| [2] Urutkan Data Menaik                                ||" << endl
		<< "============================================================" << endl;	
	setcolor(7);

    // Panggil Eror Handling
    do{
        setcolor(3);
        cout<< "\n--- Pilih Menu : ";  cin >> cek;
        setcolor(7);
    }while(eror_handling(cek) == true);
    nomor_pilih = cek;

    if(nomor_pilih == 1){
        for (int x = 0; x < jumlahdata_paket-1; x++){
            menukar = false;
            for (int y = 0; y < jumlahdata_paket-x-1; y++){
                if (utama[y].paket.operator_paket < utama[y+1].paket.operator_paket){
                    perpindahan_data(&utama[y], &utama[y+1]);
                    menukar = true;
                }
            }
            if(menukar == false){
                break;
            }
        }

        system("cls");
        tagline();
        cout << endl;
        DataPaket();
    }
    else if(nomor_pilih == 2){
        for (int x = 0; x < jumlahdata_paket-1; x++){
            menukar = false;
            for (int y = 0; y < jumlahdata_paket-x-1; y++){
                if (utama[y].paket.operator_paket > utama[y+1].paket.operator_paket){
                    perpindahan_data(&utama[y], &utama[y+1]);
                    menukar = true;
                }
            }
            if(menukar == false){
                break;
            }
        }

        system("cls");
        tagline();
        cout << endl;
        DataPaket();
    }
    else{
        setcolor(4);
        cout << "\n---- Menu Tidak Tersedia! ----" << endl;
        setcolor(7);
    }
}

void urutkan_topup(){ // Prosedur Urutkan Data Top Up
	int nomor_pilih, cek;
    bool menukar;
		 
	if(jumlahdata_top_up == 0){
		pindah_datatopup();
	}

    setcolor(8);
	cout<< endl
		<< "============================================================" << endl
    	<< "||                   Menu Urutkan Data                    ||" << endl
    	<< "============================================================" << endl
    	<< "|| [1] Urutkan Data Menurun                               ||" << endl		
    	<< "|| [2] Urutkan Data Menaik                                ||" << endl
		<< "============================================================" << endl;	
	setcolor(7);

    // Panggil Eror Handling
    do{
        setcolor(3);
        cout<< "\n--- Pilih Menu : ";  cin >> cek;
        setcolor(7);
    }while(eror_handling(cek) == true);
    nomor_pilih = cek;

    if(nomor_pilih == 1){
        for (int x = 0; x < jumlahdata_top_up-1; x++){
            menukar = false;
            for (int y = 0; y < jumlahdata_top_up-x-1; y++){
                if (utama[y].top_up.operator_top_up < utama[y+1].top_up.operator_top_up){
                    perpindahan_data(&utama[y], &utama[y+1]);
                    menukar = true;
                }
            }
            if(menukar == false){
                break;
            }
        }

        system("cls");
        tagline();
        cout << endl;
        DataTopup();
    }
    else if(nomor_pilih == 2){
        for (int x = 0; x < jumlahdata_top_up-1; x++){
            menukar = false;
            for (int y = 0; y < jumlahdata_top_up-x-1; y++){
                if (utama[y].top_up.operator_top_up > utama[y+1].top_up.operator_top_up){
                    perpindahan_data(&utama[y], &utama[y+1]);
                    menukar = true;
                }
            }
            if(menukar == false){
                break;
            }
        }

        system("cls");
        tagline();
        cout << endl;
        DataTopup();
    }
    else{
        setcolor(4);
        cout << "\n---- Menu Tidak Tersedia! ----" << endl;
        setcolor(7);
    }
}


// Fungsi yang mengembalikan string ke huruf kecil
string hurufkecil(string huruf){
    for(int x = 0;x < huruf.length();x++){
        huruf[x] = tolower(huruf[x]);
    }
    return huruf;
}

// Fungsi untuk memeriksa kesamaan kata
bool checkkata(string cari, string arrayKata){
    int posisi = 0, index_str;
    bool ketemu = false;
    while((index_str = arrayKata.find(cari, posisi)) != string::npos){
        ketemu = true;
        posisi = index_str + 1;
    }
    if(ketemu){
        return true;
    }
    else{
        return false;
    }
}

// Fungsi untuk melakuka searching pulsa, paket, dan topup
int searching_pulsa(int jumlahdata_pulsa){ // Fungsi Searching Pulsa
	bool point;
	string cari;
    int data, index = 0, simpan_data[100];
    
    cout<< "     SEARCHING OPERATOR PULSA" << endl
    	<< "----------------------------------" << endl
    	<< "Nama Operator : "; fflush(stdin);     
    getline(cin, cari);
	cari = hurufkecil(cari);
	

    for (int i = 0; i < jumlahdata_pulsa ; i++){
		string dicari;
		dicari = utama[i].pulsa.operator_pulsa;
		dicari = hurufkecil(dicari);

        while(checkkata(cari, dicari) == true){
            point = true;
            simpan_data[index] = i;
            index++;
            break;
        }
    }

    if(point == 1){
	    system("cls");
	    tagline();
	    
	    cout<< "\n\n----------------------- DATA DITEMUKAN ---------------------- " << endl
			<< endl;
			
        for (int j = 0; j < index ; j++){
            data = simpan_data[j];
            cout<< "                      DATA PULSA KE - " << data + 1 << endl
	    		<< "                      -------------------" << endl
				<< "Operator Pulsa        : " << utama[data].pulsa.operator_pulsa << endl
				<< "Jumlah Pulsa          : " << utama[data].pulsa.jumlah_pulsa << endl
				<< "Harga Pulsa           : Rp. " << utama[data].pulsa.harga_pulsa << endl
				<< endl;
        }
    }

    else{
        cout<< ">>>>>>>> -DATA TIDAK ADA- <<<<<<<<" << endl;
    }

	return 0;
}

int searching_paket(int jumlahdata_paket){ // Fungsi Searching Paket
	bool point;
	string cari;
    int data, index = 0, simpan_data[100];

    cout<< "     SEARCHING OPERATOR PAKET" << endl
    	<< "----------------------------------" << endl
    	<< "Nama Operator : "; fflush(stdin);          
    getline(cin, cari);
	cari = hurufkecil(cari);
	

    for (int i = 0; i < jumlahdata_paket ; i++){
		string dicari;
		dicari = utama[i].paket.operator_paket;
		dicari = hurufkecil(dicari);

        while(checkkata(cari, dicari) == true){
            point = true;
            simpan_data[index] = i;
            index++;
            break;
        }
    }
    
    if(point == 1){
    	system("cls");
   		tagline();
   		
  	  	cout<< "\n\n----------------------- DATA DITEMUKAN ---------------------- " << endl
			<< endl;
			
        for (int j = 0; j < index ; j++){
            data = simpan_data[j];
            cout<< "                      DATA PAKET KE - " << data + 1 << endl
	        	<< "                      -------------------" << endl
				<< "Operator Paket        : " << utama[data].paket.operator_paket << endl
				<< "Jumlah Paket          : " << utama[data].paket.jumlah_paket << endl	
				<< "Harga Paket           : Rp. " << utama[data].paket.harga_paket << endl		
				<< endl;
        }
    }

    else{
        cout<< ">>>>>>>> -DATA TIDAK ADA- <<<<<<<<" << endl;
    }

	return 0;
}

int searching_topup(int jumlahdata_top_up){ // Fungsi Searching Top Up
	bool point;
	string cari;
    int data, index = 0, simpan_data[100];
    
 	cout<< "     SEARCHING OPERATOR TOP UP" << endl
    	<< "----------------------------------" << endl
    	<< "Nama Operator : "; fflush(stdin); 
    getline(cin, cari);
	cari = hurufkecil(cari);
	

    for (int i = 0; i < jumlahdata_top_up ; i++){
		string dicari;
		dicari = utama[i].top_up.operator_top_up;
		dicari = hurufkecil(dicari);

        while(checkkata(cari, dicari) == true){
            point = true;
            simpan_data[index] = i;
            index++;
            break;
        }
    }

    if(point == 1){
    	system("cls");
  	 	tagline();	
  	 	
    	cout<< "\n\n----------------------- DATA DITEMUKAN ---------------------- " << endl
			<< endl;
			
        for (int j = 0; j < index ; j++){
            data = simpan_data[j];
            cout<< "                      DATA TOP UP KE - " << data + 1 << endl
	        	<< "                      -------------------" << endl
				<< "Operator Top Up       : " << utama[data].top_up.operator_top_up << endl
				<< "Jumlah Top Up         : " << utama[data].top_up.jumlah_top_up << endl
				<< "Harga Top Up          : Rp. " << utama[data].top_up.harga_top_up << endl
				<< endl;
        }
    }

    else{
        cout<< ">>>>>>>> -DATA TIDAK ADA- <<<<<<<<" << endl;
    }
	
	return 0;
}

// Prosedur untuk menambah data
void tambah_data(){
	int array = 100, pilih, cek;
	float cek_float;
	bool tambah_lagi; 
	char ulang;	
	
	menu_pendataan();
	
	// Panggil Eror Handling
	do{
		setcolor(3);
		cout<< "\n--- Pilih Menu Tambah : ";  cin >> cek;
		setcolor(7);
	}while(eror_handling(cek) == true);
	pilih = cek;

	sleep(1);

	if(pilih == 1){
		while(tambah_lagi == false){
			if(jumlahdata_pulsa < array){ 
				
				system("cls");
				tagline();
				pulsa.open("pulsa.txt", ios::app);
				
				int i = jumlahdata_pulsa;
				        
				cout<< "\n__________ TAMBAH PENDATAAN PULSA __________"<< endl;
				setcolor(3);
				cout<< "\nData Ke- " << i+1 << endl;
				setcolor(7);
				cout<< "-------------------------" << endl;
				    
				cout<< "Operator Pulsa          : "; fflush(stdin);
				getline(cin, utama[i].pulsa.operator_pulsa);

				// Panggil Eror Handling
				do{
					cout<< "Jumlah Pulsa            : "; cin >> cek;
				}while(eror_handling(cek) == true);
				utama[i].pulsa.jumlah_pulsa = cek;

				do{
					cout<< "Harga Pulsa             : Rp. "; cin >> cek;
				}while(eror_handling(cek) == true);
				utama[i].pulsa.harga_pulsa = cek;
				
				sleep(1);
				setcolor(2);
				cout<<"\n---BERHASIL MENAMBAH DATA PULSA---\n";
				setcolor(7);
				sleep(1);
				
				// Menambahkan data ke dalam file
				pulsa << utama[i].pulsa.operator_pulsa << ',';
        		pulsa << utama[i].pulsa.jumlah_pulsa << ',';
        		pulsa << utama[i].pulsa.harga_pulsa << '\n';
			
				pulsa.close();
				jumlahdata_pulsa++;
				
				setcolor(6);
				cout<< "\nTambah data pulsa lagi? [y/t] : "; cin >> ulang;
				setcolor(7); 
				sleep(1);
				system("cls");
				
				if (ulang == 'y' || ulang == 'Y'){
					tambah_lagi = false;
				}
				else if (ulang == 't' || ulang == 'T'){
					tambah_lagi = true;
				}
				else{
					tambah_lagi = true;
				}
			}
			
			else{
				sleep(1);
				setcolor(4);
				cout<< "BATAS TAMBAH DATA PULSA HANYA 100!" << endl; 		
				setcolor(7);
				sleep(1);
				system("cls");
			}
		}
	}
			
	else if(pilih == 2){

		while(tambah_lagi == false){
			if(jumlahdata_paket < array){ 
				
				system("cls");
				tagline();
				paket_internet.open("paket.txt", ios::app);

				int i = jumlahdata_paket;
				cout<< "\n__________ TAMBAH PENDATAAN PAKET INTERNET __________"<< endl;
				setcolor(3);
				cout<< "\nData Ke- " << i+1 << endl;
				setcolor(7);	
				cout<< "-------------------------" << endl;
				    
				cout<< "Operator Paket          : "; fflush(stdin);
				getline(cin, utama[i].paket.operator_paket);

				// Panggil Eror Handling
				do{
					cout<< "Jumlah Paket (GB)       : "; cin >> cek_float;
				}while(eror_handling(cek_float) == true);
				utama[i].paket.jumlah_paket = cek_float;

				do{
					cout<< "Harga Paket             : Rp. "; cin >> cek;
				}while(eror_handling(cek) == true);
				utama[i].paket.harga_paket = cek;
				
				sleep(1);
				setcolor(2);
				cout<<"\n---BERHASIL MENAMBAH DATA PAKET INTERNET---\n";
				setcolor(7);
				sleep(1);

				// Menambahkan data ke dalam file
				paket_internet << utama[i].paket.operator_paket << ',';
        		paket_internet << utama[i].paket.jumlah_paket << ',';
        		paket_internet << utama[i].paket.harga_paket << '\n';
			
				paket_internet.close();
				jumlahdata_paket++;
				
				setcolor(6);
				cout<< "\nTambah data paket internet lagi? [y/t] : "; cin >> ulang; 
				setcolor(7);
				sleep(1);
				system("cls");
				
				if (ulang == 'y' || ulang == 'Y'){
					tambah_lagi = false;
				}
				else if (ulang == 't' || ulang == 'T'){
					tambah_lagi = true;
				}
				else{
					tambah_lagi = true;
				}
			}
			
			else{
				sleep(1);
				setcolor(4);
				cout<< "BATAS TAMBAH DATA PAKET INTERNET HANYA 100!" << endl; 	
				setcolor(7);
				sleep(1);
				system("cls");
			}
		}
	}

	else if(pilih == 3){

		while(tambah_lagi == false){
			if(jumlahdata_top_up < array){ 
				
				system("cls");
				tagline();
				topup.open("topup.txt", ios::app);

				int i = jumlahdata_top_up;
				cout<< "\n__________ TAMBAH PENDATAAN TOP UP __________"<< endl;
				setcolor(3);
				cout<< "\nData Ke- " << i+1 << endl;
				setcolor(7);
				cout<< "-------------------------" << endl;
							
				cout<< "Operator Top Up          : "; fflush(stdin);
				getline(cin, utama[i].top_up.operator_top_up);
				
				// Panggil Eror Handling
				do{
					cout<< "Jumlah Top Up            : "; cin >> cek;
				}while(eror_handling(cek) == true);
				utama[i].top_up.jumlah_top_up = cek;

				do{
					cout<< "Harga Top Up             : Rp. "; cin >> cek;
				}while(eror_handling(cek) == true);
				utama[i].top_up.harga_top_up = cek;
				
				sleep(1);
				setcolor(2);
				cout<<"\n---BERHASIL MENAMBAH DATA TOP UP---\n";
				setcolor(7);
				sleep(1);

				// Menambahkan data ke dalam file
				topup << utama[i].top_up.operator_top_up << ',';
        		topup << utama[i].top_up.jumlah_top_up << ',';
        		topup << utama[i].top_up.harga_top_up << '\n';
			
				topup.close();
				jumlahdata_top_up++;
				
				setcolor(6);
				cout<< "\nTambah data top up lagi? [y/t] : "; cin >> ulang; 
				setcolor(7);
				sleep(1);
				system("cls");
				
				if (ulang == 'y' || ulang == 'Y'){
					tambah_lagi = false;
				}
				else if (ulang == 't' || ulang == 'T'){
					tambah_lagi = true;
				}
				else{
					tambah_lagi = true;
				}
			}

			else{
				sleep(1);
				setcolor(4);
				cout<< "--- BATAS TAMBAH DATA TOP UP HANYA 100! ---" << endl;
				setcolor(7); 		
				sleep(1);
				system("cls");
			}
		}
	}

	else if (pilih == 4){
		main();
	}

	else{
		sleep(1);
		setcolor(4);
		cout << "\n--- Menu Tidak Tersedia! ---" << endl; 
		setcolor(4);
		sleep(1);
		system("cls");
	}
}

// Prosedur untuk mengubah data
void ubah_data(){
	string operator_baru;
	int pilih, ubah_nomor, jumlah_baru, harga_baru, cek;
	float cek_float, jumlah_barufloat;
	char ulang;
	bool ubah_lagi;
	
	system("cls");
	tagline();
	menu_pendataan();

	// Panggil Eror Handling
	do{
		setcolor(3);
		cout << "\n--- Pilih Menu Ubah : ";  cin >> cek;
		setcolor(7);
	}while(eror_handling(cek) == true);
	pilih = cek;

	system("cls");
	sleep(1);
	if(pilih == 1){	
				
		if(jumlahdata_pulsa == 0){
			pindah_datapulsa();
		}

		if (jumlahdata_pulsa > 0){
			while(ubah_lagi == false){
				tagline();
				tampil_dataPulsa();	
	
				do{	
					setcolor(3);
					cout << "\n--- Pilih Nomor : "; cin >> cek;
					setcolor(7);
				}while(eror_handling(cek) == true);
				ubah_nomor = cek;
				
				system("cls");
				tagline();
			
				int i = ubah_nomor - 1;
				
				if(ubah_nomor <= 0 or ubah_nomor > jumlahdata_pulsa){
					setcolor(4);
					cout<<"\n------ DATA PULSA KE - "<< cek <<" TIDAK ADA! --------\n";
					setcolor(7);
				}
				else{
					cout<< "\n\n                  MENGUBAH DATA                               " << endl
						<< "----------------- PULSA KE - " << ubah_nomor <<" -----------------" << endl;
					cout<< "Operator Pulsa          : "; fflush(stdin);
					getline(cin, operator_baru);
		
					// Panggil Eror Handling
					do{
						cout<< "Jumlah Pulsa            : "; cin >> cek;
					}while(eror_handling(cek) == true);
					jumlah_baru = cek;
		
					do{
						cout<< "Harga Pulsa             : Rp. "; cin >> cek;
					}while(eror_handling(cek) == true);
					harga_baru = cek;
					
					utama[i].pulsa.operator_pulsa = operator_baru;
					utama[i].pulsa.jumlah_pulsa = jumlah_baru;
					utama[i].pulsa.harga_pulsa = harga_baru;
		
					sleep(1);
					setcolor(2);			
					cout<<"\n---BERHASIL MENGUBAH DATA PULSA---\n";
					setcolor(7);
					sleep(1);
					
					updatefile_pulsa();	
				}
					
				setcolor(6);
				cout<< "\nUbah data pulsa lagi? [y/t] : "; cin >> ulang;
				setcolor(7); 
				sleep(1);
				system("cls");
				
				if (ulang == 'y' || ulang == 'Y'){
					ubah_lagi = false;
				}
				else if (ulang == 't' || ulang == 'T'){
					ubah_lagi = true;
				}
				else{
					ubah_lagi = true;
				}
			}
			
		}
			
		else {
			sleep(1);
			setcolor(4);
			cout<< "\n        DAFTAR PENDATAAN KOSONG!" << endl 
				<< "--- Tidak Ada Data Yang Dapat Diubah ---" << endl; // kosong jika banyak data < 0
			setcolor(4);
			sleep(3);
			system("cls");
		}
	}
			
	else if(pilih == 2){

		if(jumlahdata_paket == 0){
			pindah_datapaket();
		}

		if (jumlahdata_paket > 0){
			while(ubah_lagi == false){
				tagline();
				tampil_dataPaket();	
	
				do{
					setcolor(3);
					cout << "\n--- Pilih Nomor : "; cin >> cek;
					setcolor(7);
				}while(eror_handling(cek) == true);
				ubah_nomor = cek;

				system("cls"); 
				tagline();
						
				int i = ubah_nomor - 1;
				
				if(ubah_nomor <= 0 or ubah_nomor > jumlahdata_paket){
					setcolor(4);
					cout<<"\n------ DATA PAKET INTERNET KE - "<< cek <<" TIDAK ADA! --------\n";	
					setcolor(7);
				} 
				else{
					cout<< "\n\n                     MENGUBAH DATA                                     " << endl
						<< "----------------- PAKET INTERNET KE - " << ubah_nomor <<" -----------------" << endl;
					cout<< "\nOperator Paket          : "; fflush(stdin);
					getline(cin, operator_baru);
					
					// Panggil Eror Handling
					do{
						cout<< "Jumlah Paket (Gb)       : "; cin >> cek_float;
					}while(eror_handling(cek_float) == true);
					jumlah_barufloat = cek_float;
		
					do{
						cout<< "Harga Paket             : Rp. "; cin >> cek;
					}while(eror_handling(cek) == true);
					harga_baru = cek;
					
					utama[i].paket.operator_paket = operator_baru;
					utama[i].paket.jumlah_paket = jumlah_barufloat;
					utama[i].paket.harga_paket = harga_baru;
					
		
					sleep(1);
					setcolor(2);			
					cout<<"\n ---BERHASIL MENGUBAH DATA PAKET INTERNET---\n";
					setcolor(7);
					sleep(1);
					
					updatefile_paket();		
				}
				
				setcolor(6);
				cout<< "\nUbah data Paket Internet lagi? [y/t] : "; cin >> ulang;
				setcolor(7); 
				sleep(1);
				system("cls");
				
				if (ulang == 'y' || ulang == 'Y'){
					ubah_lagi = false;
				}
				else if (ulang == 't' || ulang == 'T'){
					ubah_lagi = true;
				}
				else{
					ubah_lagi = true;
				}
			}
		}
			
		else {
			sleep(1);
			setcolor(4);
			cout<< "\n        DAFTAR PENDATAAN KOSONG!" << endl 
				<< "--- Tidak Ada Data Yang Dapat Diubah ---" << endl; // kosong jika banyak data < 0
			setcolor(4);
			sleep(3);
			system("cls");
		}
	}

	else if(pilih == 3){	

		if(jumlahdata_top_up == 0){
			pindah_datatopup();
		}

		if (jumlahdata_top_up > 0){
			while(ubah_lagi == false){
				tagline();
				tampil_dataTop_up();	
	
				do{
					setcolor(3);
					cout << "\nPilih Nomor : "; cin >> cek;
					setcolor(7);
				}while(eror_handling(cek) == true);
				ubah_nomor = cek;
			
				system("cls");
				tagline();
				
				int i = ubah_nomor - 1;

				if(ubah_nomor <= 0 or ubah_nomor > jumlahdata_top_up){
					setcolor(4);
					cout<<"\n------ DATA TOP UP KE - "<< cek <<" TIDAK ADA! --------\n";
					setcolor(7);
				}
				else{
					cout<< "\n\n                   MENGUBAH DATA                               " << endl
						<< "----------------- TOP UP KE - " << ubah_nomor <<" -----------------" << endl;
					cout<< "Operator Top Up         : "; fflush(stdin);
					getline(cin, operator_baru);
		
					// Panggil Eror Handling
					do{
						cout<< "Jumlah Top Up           : "; cin >> cek;
					}while(eror_handling(cek) == true);
					jumlah_baru = cek;
		
					do{
						cout<< "Harga Top Up            : Rp. "; cin >> cek;
					}while(eror_handling(cek) == true);
					harga_baru = cek;
					
					utama[i].top_up.operator_top_up = operator_baru;
					utama[i].top_up.jumlah_top_up = jumlah_baru;
					utama[i].top_up.harga_top_up = harga_baru;

					sleep(1);
					setcolor(2);				
					cout<<"\n---BERHASIL MENGUBAH DATA TOP UP---\n";
					setcolor(7);
					sleep(1);
		
					updatefile_topup();
				}
				
				setcolor(6); 
				cout<< "\nUbah data Paket Internet lagi? [y/t] : "; cin >> ulang;
				setcolor(7); 
				sleep(1);
				system("cls");
				
				if (ulang == 'y' || ulang == 'Y'){
					ubah_lagi = false;
				}
				else if (ulang == 't' || ulang == 'T'){
					ubah_lagi = true;
				}
				else{
					ubah_lagi = true;
				}
			}
		}
			
		else {
			sleep(1);
			setcolor(4);
			cout<< "\n        DAFTAR PENDATAAN KOSONG!" << endl 
				<< "--- Tidak Ada Data Yang Dapat Diubah ---" << endl; // kosong jika banyak data < 0
			setcolor(4);
			sleep(3);
			system("cls");
		}
	}
		
	else if (pilih == 4){
		main();
	}

	else{
		sleep(1);
		setcolor(4);
		cout << "\n---- Menu Tidak Tersedia! ----" << endl;
		setcolor(7);
		sleep(1);
		system("cls");
	}
}

// Prosedur untuk menghapus data
void hapus_data(){
	int pilih, hapus_nomor, cek;
	char ulang;
	bool hapus_lagi;

	system("cls");
	tagline();	
	menu_pendataan();

	do{
		setcolor(3);
		cout<< "\n--- Pilih Menu Hapus : ";  cin >> cek; 
		setcolor(7);
	}while(eror_handling(cek) == true);
	pilih = cek;

	sleep(1);	
	if(pilih == 1){
		system("cls");
		if(jumlahdata_pulsa == 0){
			pindah_datapulsa();
		}

		if (jumlahdata_pulsa > 0){
			while(hapus_lagi == false){
				tagline();
				tampil_dataPulsa();	
				
				// Panggil Eror Handling
				do{
					setcolor(3);
					cout << "\n--- Pilih Nomor : "; cin >> cek;
					setcolor(7);
				}while(eror_handling(cek) == true);
				hapus_nomor = cek;
	
				hapus_nomor -= 1;

				if(hapus_nomor < 0 or hapus_nomor > jumlahdata_pulsa-1){
					sleep(1);
					setcolor(4);
					cout<<"\n------ DATA PULSA KE "<< cek << " TIDAK ADA! --------\n";
					setcolor(7);
				}
				else{
					jumlahdata_pulsa--;
					
					for(int i = hapus_nomor; i < jumlahdata_pulsa; i++){
						utama[i] = utama[i+1];
					}

					sleep(1);
					setcolor(2);				
					cout<<"\n--- BERHASIL MENGHAPUS DATA PULSA KE - " << hapus_nomor + 1 << " ---\n";
					setcolor(2);	
					sleep(2);	
									
					updatefile_pulsa();
					
					system("cls");
					tagline();
			
					tampil_dataPulsa();
				}
				
				setcolor(6);
				cout<< "\nHapus data Pulsa lagi? [y/t] : "; cin >> ulang;
				setcolor(7); 
				
				sleep(1);
				system("cls");
								
				if (ulang == 'y' || ulang == 'Y'){
					hapus_lagi = false;
				}
				else if (ulang == 't' || ulang == 'T'){
					hapus_lagi = true;
				}
				else{
					hapus_lagi = true;
				}
			}			
		}
		
		else {
			tagline();
			sleep(1);
			setcolor(4);
			cout<< "\n        DAFTAR PENDATAAN KOSONG!" << endl 
				<< "--- Tidak Ada Data Yang Dapat Dihapus ---" << endl; // kosong jika banyak data < 0
			setcolor(4);
			sleep(3);
			system("cls");
		}
	}
			
	else if(pilih == 2){
		system("cls");
		
		if(jumlahdata_paket == 0){
			pindah_datapaket();
		}

		if (jumlahdata_paket > 0){
			while(hapus_lagi == false){
				tagline();
				tampil_dataPaket();	
				
				// Panggil Eror Handling
				do{
					setcolor(3);
					cout << "\n--- Pilih Nomor : "; cin >> cek;
					setcolor(7);
				}while(eror_handling(cek) == true);
				hapus_nomor = cek;
				
				hapus_nomor -= 1;

				if(hapus_nomor < 0 or hapus_nomor > jumlahdata_paket-1){
					sleep(1);
					setcolor(4);
					cout<<"\n------ DATA PAKET KE "<< cek << " TIDAK ADA! --------\n";
					setcolor(7);
				}
				else{
					jumlahdata_paket--;
					for(int i = hapus_nomor; i < jumlahdata_paket; i++){
						utama[i] = utama[i+1];
					}

					sleep(1);
					setcolor(2);				
					cout<<"\n--- BERHASIL MENGHAPUS DATA PAKET INTERNET KE - " << hapus_nomor + 1 << " ---\n";
					setcolor(7);	
					sleep(2);	
					
					updatefile_paket();		
					
					system("cls");
					tagline();
					
					tampil_dataPaket();
				}
					
				setcolor(6);
				cout<< "\nHapus data Paket Internet lagi? [y/t] : "; cin >> ulang;
				setcolor(7); 
				
				sleep(1);
				system("cls");
								
				if (ulang == 'y' || ulang == 'Y'){
					hapus_lagi = false;
				}
				else if (ulang == 't' || ulang == 'T'){
					hapus_lagi = true;
				}
				else{
					hapus_lagi = true;
				}
			}	
		}
		
		else {
			tagline();
			sleep(1);
			setcolor(4);
			cout<< "\n        DAFTAR PENDATAAN KOSONG!" << endl 
				<< "--- Tidak Ada Data Yang Dapat Dihapus ---" << endl; // kosong jika banyak data < 0
			setcolor(4);
			sleep(3);
			system("cls");
		}
	}
			
	else if(pilih == 3){
		system("cls");
		
		if(jumlahdata_top_up == 0){
			pindah_datatopup();
		}

		if (jumlahdata_top_up > 0){
			while(hapus_lagi == false){
				tagline();
				tampil_dataTop_up();	
				
				// Panggil Eror Handling
				do{
					setcolor(3);
					cout << "\n--- Pilih Nomor : "; cin >> cek;
					setcolor(7);
				}while(eror_handling(cek) == true);
				hapus_nomor = cek;
				
				hapus_nomor -= 1;

				if(hapus_nomor < 0 or hapus_nomor > jumlahdata_top_up-1){
					sleep(1);
					setcolor(4);
					cout<<"\n------ DATA TOP UP KE "<< cek << " TIDAK ADA! --------\n";
					setcolor(7);
				}
				else{
					jumlahdata_top_up--;
					for(int i = hapus_nomor; i < jumlahdata_top_up; i++){
						utama[i] = utama[i+1];
					}

					sleep(1);
					setcolor(2);				
					cout<<"\n--- BERHASIL MENGHAPUS DATA TOP UP KE - " << hapus_nomor + 1 << " ---\n";
					setcolor(7);	
					sleep(2);	

					updatefile_topup();
					
					system("cls");
					tagline();	
					
					tampil_dataTop_up();
				}
				
				
				setcolor(6);
				cout<< "\nHapus data Top Up lagi? [y/t] : "; cin >> ulang;
				setcolor(7); 
				
				sleep(1);
				system("cls");
								
				if (ulang == 'y' || ulang == 'Y'){
					hapus_lagi = false;
				}
				else if (ulang == 't' || ulang == 'T'){
					hapus_lagi = true;
				}
				else{
					hapus_lagi = true;
				}
			}		
		}
		
		else {
			tagline();
			sleep(1);
			setcolor(4);
			cout<< "\n        DAFTAR PENDATAAN KOSONG!" << endl 
				<< "--- Tidak Ada Data Yang Dapat Dihapus ---" << endl; // kosong jika banyak data < 0
			setcolor(4);
			sleep(3);
			system("cls");
		}
	}

	else if (pilih == 4){
		main();
	}
			
	else{
		sleep(1);
		setcolor(4);
		cout << "\n---- Menu Tidak Tersedia! ----" << endl;
		setcolor(7);
		sleep(1);
		system("cls");			
	}
}

// Prosedur Tampilan Ketika Keluar Dari Program
void keluar(){
	sleep(1);
	system("cls");
	tagline();
	
	setcolor(8);
 	cout << "============================================================================================================================================================================" << endl;
    cout << "|                                                   A N D A   T E L A H   K E L U A R   D A R I   P R O G R A M                                                            |" << endl;
   	cout << "============================================================================================================================================================================" << endl;
    cout << "|                                                  Info: Terima kasih telah menggunakan program dari Kelompok 3 <3                                                         |" << endl;
    cout << "============================================================================================================================================================================" << endl;
    setcolor(7);
    exit(0);
}


// Prosedur Untuk membuat file eksternal
void file_pulsa(){
	pulsa.open("pulsa.txt", ios::in);

    // jika file eksternal tidak ditemukan, maka akan dibuat secara otomatis
    if (!pulsa.is_open()){
        pulsa.open("pulsa.txt", ios::out | ios::trunc);
        pulsa.close();
    }
    pulsa.close();
}

void file_paket(){
	paket_internet.open("paket.txt", ios::in);

    // jika file eksternal tidak ditemukan, maka akan dibuat secara otomatis
    if (!paket_internet.is_open()){
        paket_internet.open("paket.txt", ios::out | ios::trunc);
        paket_internet.close();
    }
    paket_internet.close();
}

void file_topup(){
	topup.open("topup.txt", ios::in);

    // jika file eksternal tidak ditemukan, maka akan dibuat secara otomatis
    if (!topup.is_open()){
        topup.open("topup.txt", ios::out | ios::trunc);
        topup.close();
    }
    topup.close();
}

// Prosedur untuk mengupdate data file eksternal
void updatefile_pulsa(){
    pulsa.open("pulsa.txt", ios::out);

    // Untuk mengupdate seluruh perubahan data di dalam file eksternal
    for (int i = 0; i < jumlahdata_pulsa; i++){
        pulsa << utama[i].pulsa.operator_pulsa << ',';
        pulsa << utama[i].pulsa.jumlah_pulsa << ',';
        pulsa << utama[i].pulsa.harga_pulsa << '\n';
    }

    pulsa.close();
}

void updatefile_paket(){
    paket_internet.open("paket.txt", ios::out);

    // Untuk mengupdate seluruh perubahan data di dalam file eksternal
    for (int i = 0; i < jumlahdata_paket; i++){
        paket_internet << utama[i].paket.operator_paket << ',';
        paket_internet << utama[i].paket.jumlah_paket << ',';
        paket_internet << utama[i].paket.harga_paket << '\n';
    }

    paket_internet.close();
}

void updatefile_topup(){
    topup.open("topup.txt", ios::out);

    // Untuk mengupdate seluruh perubahan data di dalam file eksternal
    for (int i = 0; i < jumlahdata_top_up; i++){
        topup << utama[i].top_up.operator_top_up << ',';
        topup << utama[i].top_up.jumlah_top_up << ',';
        topup << utama[i].top_up.harga_top_up << '\n';
    }

    topup.close();
}

// Prosedur untuk memindahkan data file eksternal ke dalam program
void pindah_datapulsa(){

    pulsa.open("pulsa.txt", ios::in);

    string jumlah, harga;

    while(!pulsa.eof()){

        getline(pulsa, utama[jumlahdata_pulsa].pulsa.operator_pulsa, ',');
        getline(pulsa, jumlah, ',');
        getline(pulsa, harga, '\n');

        // Konversi str ke int
        stringstream strjumlah(jumlah);
        stringstream strharga(harga);

        strjumlah >> utama[jumlahdata_pulsa].pulsa.jumlah_pulsa;
        strharga >> utama[jumlahdata_pulsa].pulsa.harga_pulsa;
        
        if(pulsa.eof()){
            break;
        }
        jumlahdata_pulsa++;
    }
    pulsa.close();
}

void pindah_datapaket(){

    paket_internet.open("paket.txt", ios::in);

    string jumlah, harga;

    while(!paket_internet.eof()){

        getline(paket_internet, utama[jumlahdata_paket].paket.operator_paket, ',');
        getline(paket_internet, jumlah, ',');
        getline(paket_internet, harga, '\n');

		// Konversi str ke float
        stringstream strjumlah(jumlah);
        // Konversi str ke int
        stringstream strharga(harga);

        strjumlah >> utama[jumlahdata_paket].paket.jumlah_paket;
        strharga >> utama[jumlahdata_paket].paket.harga_paket;
        
        if(paket_internet.eof()){
            break;
        }
        jumlahdata_paket++;
    }
    paket_internet.close();
}

void pindah_datatopup(){

    topup.open("topup.txt", ios::in);

    string jumlah, harga;

    while(!topup.eof()){

        getline(topup, utama[jumlahdata_top_up].top_up.operator_top_up, ',');
        getline(topup, jumlah, ',');
        getline(topup, harga, '\n');

        // Konversi str ke int
        stringstream strjumlah(jumlah);
        stringstream strharga(harga);

        strjumlah >> utama[jumlahdata_top_up].top_up.jumlah_top_up;
        strharga >> utama[jumlahdata_top_up].top_up.harga_top_up;
        
        if(topup.eof()){
            break;
        }
        jumlahdata_top_up++;
    }
    topup.close();
}