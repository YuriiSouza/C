#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char customer_name[50];
    char order_description[100];
    char status[20];
    char order_time[6];
} Order;

typedef struct Node {
    Order order;
    struct Node* next;
} Node;

Node* add_order_to_end(Node* head, int id, const char* customer_name, const char* order_description, const char* status, const char* order_time) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->order.id = id;
    strcpy(new_node->order.customer_name, customer_name);
    strcpy(new_node->order.order_description, order_description);
    strcpy(new_node->order.status, status);
    strcpy(new_node->order.order_time, order_time);
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;

    return head;
}

Node* remove_order_by_id(Node* head, int id) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->order.id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Order with ID %d not found.\n", id);
        return head;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Order with ID %d removed successfully.\n", id);
    return head;
}

void update_order_status(Node* head, int id, const char* new_status) {
    Node* temp = head;

    while (temp != NULL && temp->order.id != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Order with ID %d not found.\n", id);
        return;
    }

    if (strcmp(new_status, "Aguardando") == 0 || strcmp(new_status, "Em Preparação") == 0 || strcmp(new_status, "Concluído") == 0) {
        strcpy(temp->order.status, new_status);
        printf("Order status updated to '%s' for ID %d.\n", new_status, id);
    } else {
        printf("Invalid status. Please use 'Aguardando', 'Em Preparação', or 'Concluído'.\n");
    }
}

void search_orders_by_customer_name(Node* head, const char* customer_name) {
    Node* temp = head;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->order.customer_name, customer_name) == 0) {
            printf("Order ID: %d\n", temp->order.id);
            printf("Description: %s\n", temp->order.order_description);
            printf("Status: %s\n", temp->order.status);
            printf("Order Time: %s\n\n", temp->order.order_time);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("No orders found for customer '%s'.\n", customer_name);
    }
}

int compare_orders_by_time(const void* a, const void* b) {
    Node* order_a = *(Node**)a;
    Node* order_b = *(Node**)b;

    return strcmp(order_b->order.order_time, order_a->order.order_time);
}

void display_orders_by_status(Node* head, const char* status) {
    Node* temp = head;
    Node* orders[100];  // Array to store orders matching the status
    int count = 0;

    // Collect orders with the matching status
    while (temp != NULL) {
        if (strcmp(temp->order.status, status) == 0) {
            orders[count++] = temp;
        }
        temp = temp->next;
    }

    if (count == 0) {
        printf("No orders found with status '%s'.\n", status);
        return;
    }

    // Sort the orders by order time (from latest to earliest)
    qsort(orders, count, sizeof(Node*), compare_orders_by_time);

    // Display the sorted orders
    printf("Orders with status '%s':\n", status);
    for (int i = 0; i < count; i++) {
        printf("Order ID: %d\n", orders[i]->order.id);
        printf("Customer Name: %s\n", orders[i]->order.customer_name);
        printf("Description: %s\n", orders[i]->order.order_description);
        printf("Status: %s\n", orders[i]->order.status);
        printf("Order Time: %s\n\n", orders[i]->order.order_time);
    }
}

void sort_orders_by_time(Node* head, int ascending) {
    Node* temp = head;
    Node* orders[100];
    int count = 0;

    while (temp != NULL) {
        orders[count++] = temp;
        temp = temp->next;
    }

    if (ascending) {
        qsort(orders, count, sizeof(Node*), compare_orders_by_time);
    } else {
        qsort(orders, count, sizeof(Node*), compare_orders_by_time);
        for (int i = 0; i < count / 2; i++) {
            Node* temp_order = orders[i];
            orders[i] = orders[count - i - 1];
            orders[count - i - 1] = temp_order;
        }
    }

    printf("Orders sorted by time:\n");
    for (int i = 0; i < count; i++) {
        printf("Order ID: %d\n", orders[i]->order.id);
        printf("Customer Name: %s\n", orders[i]->order.customer_name);
        printf("Description: %s\n", orders[i]->order.order_description);
        printf("Status: %s\n", orders[i]->order.status);
        printf("Order Time: %s\n\n", orders[i]->order.order_time);
    }
}

void list_all_orders(Node* head) {
    Node* temp = head;
    Node* orders[100];
    int count = 0;

    while (temp != NULL) {
        orders[count++] = temp;
        temp = temp->next;
    }

    qsort(orders, count, sizeof(Node*), compare_orders_by_time);

    printf("All Orders:\n");
    for (int i = 0; i < count; i++) {
        printf("Order ID: %d\n", orders[i]->order.id);
        printf("Customer Name: %s\n", orders[i]->order.customer_name);
        printf("Description: %s\n", orders[i]->order.order_description);
        printf("Status: %s\n", orders[i]->order.status);
        printf("Order Time: %s\n\n", orders[i]->order.order_time);
    }
}

void free_memory(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int choice;
    Order order;

    while (1) {
        printf("1. Add Order\n2. Remove Order\n3. Update Order Status\n4. List Orders\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add an order (example)
                printf("Enter Order ID: ");
                scanf("%d", &order.id);
                printf("Enter Customer Name: ");
                scanf(" %[^\n]s", order.customer_name);
                printf("Enter Description: ");
                scanf(" %[^\n]s", order.order_description);
                printf("Enter Status: ");
                scanf(" %[^\n]s", order.status);
                time_t t;
                time(&t);
                strftime(order.order_time, sizeof(order.order_time), "%Y-%m-%d %H:%M:%S", localtime(&t));
                head = add_order_to_end(head, order.id, order.customer_name, order.order_description, order.status, order.order_time);
                break;
            case 2:
                // Remove an order (example)
                printf("Enter Order ID to remove: ");
                scanf("%d", &order.id);
                head = remove_order_by_id(head, order.id);
                break;
            case 3:
                // Update status (example)
                printf("Enter Order ID to update: ");
                scanf("%d", &order.id);
                printf("Enter new Status: ");
                scanf(" %[^\n]s", order.status);
                update_order_status(head, order.id, order.status);
                break;
            case 4:
                // List orders (example)
                list_all_orders(head);
                break;
            case 5:
                // Free memory and exit
                free_memory(head);
                exit(0);
        }
    }

    return 0;
}

