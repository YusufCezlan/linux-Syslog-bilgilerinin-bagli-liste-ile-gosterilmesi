#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//liste düðümü ve node 
typedef struct Node {
    char timestamp[32];    // Kayýt zamaný
    char level[16];        // Log seviyesi (INFO, ERROR, DEBUG)
    char message[256];     // Log mesajý
    struct Node* next;      // Sonraki düðümün adresi
    struct Node* prev;      // Önceki düðümün adresi
} Node;


Node* createNode(char* level, char* msg) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // Zaman damgasýný al
    time_t now = time(NULL);
    strftime(newNode->timestamp, 32, "%Y-%m-%d %H:%M:%S", localtime(&now));
    
    strncpy(newNode->level, level, 16);
    strncpy(newNode->message, msg, 256);
    
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

/**
 * @brief Listeye sonuna yeni log ekler (Queue mantýðý).
 */
void appendLog(Node** head, char* level, char* msg) {
    Node* newNode = createNode(level, msg);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    newNode->prev = temp;
}

/**
 * @brief Tüm syslog kayýtlarýný ekrana yazdýrýr.
 */
void displayLogs(Node* head) {
    printf("\n--- Mevcut Syslog Kayitlari ---\n");
    Node* temp = head;
    while (temp != NULL) {
        printf("[%s] %-7s: %s\n", temp->timestamp, temp->level, temp->message);
        temp = temp->next;
    }
    printf("-------------------------------\n");
}

int main() {
    Node* syslogList = NULL;

    // Örnek log kayýtlarý ekleniyor
    appendLog(&syslogList, "INFO", "Sistem baslatildi.");
    appendLog(&syslogList, "DEBUG", "Bagli liste bellek tahsisi yapildi.");
    appendLog(&syslogList, "ERROR", "Disk doluluk orani %90 uzerinde!");
    appendLog(&syslogList, "INFO", "Kullanici 'admin' giris yapti.");

    // Loglarý listele
    displayLogs(syslogList);

    // Belleði temizleme (Free memory)
    Node* current = syslogList;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
