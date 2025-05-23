#include <iostream>
using namespace std;

struct order {
    string nama;
    string rroti;
    int hg;
};

struct q {
    order info;
    q *next;
};

q *depan, *belakang;
q *top = NULL;

void sutart() {
    depan = belakang = NULL;
}

bool qksng() {
    return depan == NULL;
}

void enq(order pesanan) {
    q *node = new q;
    node->info = pesanan;
    node->next = NULL;
    
    if (qksng()) {
        depan = belakang = node;
    } else {
        belakang->next = node;
        belakang = node;
    }
    cout << "Pesanan " << pesanan.rroti << " atas nama " << pesanan.nama << " telah ditambahkan ke antrian.\n";
    // Pesanan Roti Buaya atas nama Alip telah ditambahkan ke q
}

void dq() {
    if (qksng()) {
        cout << "Antrian kosong, tidak ada pesanan untuk dilayani.\n";
        return;
    }
    
    q *bantu = depan;
    order pesanan = bantu->info;
    
    //anuan <- <<#FF0000
    q *sf = new q;
    sf->info = pesanan;
    sf->next = top;
    top = sf;
    
    depan = depan->next;
    delete bantu;
    
    cout << "Pesanan " << pesanan.rroti << " atas nama " << pesanan.nama << " telah dilayani.\n";
    // Pain au chocolat, Croissant, Strawberry Shortcake, Basque Burnt Cheesecake
}

void showq() {
    if (qksng()) {
        cout << "Antrian pesanan kosong.\n";
        return;
    }
    
    cout << "Daftar Pesanan dalam Antrian:\n";
    q *current = depan;
    int counter = 1;
    while (current != NULL) {
        cout << counter++ << ". " << current->info.nama << " - " 
             << current->info.rroti << " - Rp" << current->info.hg << endl;
        current = current->next;
    }
}

void cancel() {
    if (qksng()) {
        cout << "Antrian kosong, tidak ada pesanan untuk dibatalkan.\n";
        return;
    }
    
    if (depan == belakang) {
        delete depan;
        depan = belakang = NULL;
    } else {
        q *current = depan;
        while (current->next != belakang) {
            current = current->next;
        }
        delete belakang;
        belakang = current;
        belakang->next = NULL;
    }
    cout << "Pesanan terakhir dalam antrian telah dibatalkan.\n";
}

void hafalanluarkepala() {
    if (top == NULL) {
        cout << "Belum ada pesanan yang dilayani.\n";
        return;
    }
    
    cout << "Daftar Pesanan yang Sudah Dilayani:\n";
    q *TOLONG = top;
    int counter = 1;
    while (TOLONG != NULL) {
        cout << counter++ << ". " << TOLONG->info.nama << " - " 
             << TOLONG->info.rroti << " - Rp" << TOLONG->info.hg << endl;
        TOLONG = TOLONG->next;
    }
}

int main() {
    sutart();
    int pilihan;
    
    do {
        cout << "\n Toko Roti Inigo Montoya \n";
        cout << "1. Pesan Roti\n";
        cout << "2. Layani Pembeli\n";
        cout << "3. Daftar Pesanan Roti\n";
        cout << "4. Cancel Order\n";
        cout << "5. Tampilkan Pelanggan yang puas\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1: {
                order p;
                cout << "Nama Pembeli: ";
                getline(cin, p.nama);
                cout << "Jenis Roti: ";
                getline(cin, p.rroti);
                cout << "Total Harga: ";
                cin >> p.hg;
                enq(p);
                break;
            }
            case 2:
                dq();
                break;
            case 3:
                showq();
                break;
            case 4:
                cancel();
                break;
            case 5:
                hafalanluarkepala();
                break;
            case 0:
                cout << "Segera makan rotinya.\n";
                break;
            default:
                cout << "ERR.\n";
        }
    } while (pilihan != 0);
    
    return 0;
}