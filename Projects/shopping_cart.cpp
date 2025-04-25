#include <iostream>
using namespace std;

struct Product {
    string name;
    int id;
    int price;
    int quantity;
};

struct Cart { // Linked List of Cart products
    Product product;
    Cart *next;
};

struct user { // Linked List of Users
    string username;
    Cart *cart;
    user *next;
};

void welcome_page(user *userList);
void welcome_user(user *tempUser);

Product createProduct(string name, int id, int price, int quantity) {
    // Creates a new product variable
    Product item;
    item.name = name;
    item.id = id;
    item.price = price;
    item.quantity = quantity;
    return item;
}

Cart *create_productList() {
    // Creates a linked list of products available
    Cart *products = new Cart;
    Cart *currItem = products;
    currItem->product = createProduct("Keyboard", 1101, 599, 20);
    currItem->next = new Cart;
    currItem = currItem->next;
    currItem->product = createProduct("Bluetooth Speaker", 1102, 999, 40);
    currItem->next = new Cart;
    currItem = currItem->next;
    currItem->product = createProduct("Bag", 1103, 800, 20);
    currItem->next = new Cart;
    currItem = currItem->next;
    currItem->product = createProduct("T-Shirt", 1104, 299, 20);
    currItem->next = new Cart;
    currItem = currItem->next;
    currItem->product = createProduct("Jeans", 1105, 500, 20);
    currItem->next = new Cart;
    currItem = currItem->next;
    currItem->product = createProduct("Shoes", 1106, 1299, 20);
    currItem->next = new Cart;
    currItem = currItem->next;
    currItem->product = createProduct("Smart Watch", 1107, 1000, 20);
    currItem->next = new Cart;
    currItem = currItem->next;
    currItem->product = createProduct("Mobile Charger", 1108, 200, 20);
    currItem->next = NULL;

    // Add More Items
    return products;
}

Cart *productList = create_productList(); // Global Variable

void display_productList(Cart *productList) {
    // Displays the products available to buy
    Cart *item = productList;
    cout << "Products Available: " << endl
         << endl;
    while (item != NULL) {
        cout << "ID:" << item->product.id << "   "
             << "Rs." << item->product.price << "   "
             << item->product.name
             << endl;
        item = item->next;
    }
    cout << endl;
}

void view_cart(user *u) {
    // Displays the products in a user's cart
    Cart *item = u->cart;
    if (item == NULL) {
        cout << "Your Cart is empty!" << endl;
        return;
    }
    cout << endl
         << u->username << "'s Cart: " << endl;
    while (item != NULL) {
        cout << "ID: " << item->product.id << endl
             << item->product.name << endl
             << "Rs." << item->product.price << endl
             << "Quantity: " << item->product.quantity << endl
             << endl;
        item = item->next;
    }
}

user *createUser(user *userList, string username) {
    // Appends a new user node in the userList Linked List
    if (userList == NULL) {
        user *u = new user;
        u->username = username;
        u->next = nullptr;
        u->cart = NULL;
        return u;
    }
    user *temp = userList;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new user;
    temp = temp->next;
    temp->next = NULL;
    temp->username = username;
    temp->cart = NULL;
    return userList; // Returns the head of user Linked List
}

void create_new_user(user *userList) {
    // Creates a new user in the database
create_new_user:
    string inputUsername;
    cout << endl
         << "Enter a new username: " << endl;
    cin >> inputUsername;
    user *tempUser = userList;
    while (tempUser != NULL) {
        if (tempUser->username == inputUsername) {
            cout << "Username already exists!" << endl;
            goto create_new_user;
        }
        tempUser = tempUser->next;
    }
    userList = createUser(userList, inputUsername);
    tempUser = userList;
    while (tempUser->username != inputUsername) {
        tempUser = tempUser->next;
    }
    welcome_user(tempUser);
}

user *userList = createUser(userList, "Nitin"); // Already existing user

void login(user *userList) {
    // Login page for the user
login:
    cout << "Enter your username: ";
    string inputUser;
    cin >> inputUser;
    user *tempUser = userList;
    while (tempUser != NULL) {
        if (tempUser->username == inputUser) {
            break;
        }
        tempUser = tempUser->next;
    }
    if (tempUser == NULL) {
        cout << "User Not Found!" << endl;
    user_not_found:
        cout << endl
             << "What would you like to do now?" << endl;
        cout << "1. Create New User" << endl
             << "2. Go Back to Login" << endl
             << "-> ";
        int input;
        cin >> input;
        if (input == 1) {
            create_new_user(userList);
            return;
        } else if (input == 2) {
            goto login;
        } else {
            cout << "Enter a valid input!" << endl;
            goto user_not_found;
        }
    }
    welcome_user(tempUser);
}

void add_item_in_cart(user *tempUser) {
product_ID:
    cout << endl
         << "Enter the products's ID to add it to your cart: " << endl;
    int prodID;
    cin >> prodID;
    Cart *prodCart = productList;
    while (prodCart->product.id != prodID) {
        prodCart = prodCart->next;
    }
    if (prodCart == NULL) {
        cout << "Invalid Product ID!" << endl;
        goto product_ID;
    }
    Cart *tempCartID = tempUser->cart;
    while (tempCartID != NULL) {
        if (tempCartID->product.id == prodID) {
            tempCartID->product.quantity++;
            return;
        }
        tempCartID = tempCartID->next;
    }
    Cart *newProd = new Cart;
    newProd->product = prodCart->product;
    newProd->next = NULL;
    newProd->product.quantity = 1;

    if (tempUser->cart == NULL) {
        tempUser->cart = newProd;
        return;
        // FIXME:
    }
    Cart *tempCart = tempUser->cart;
    while (tempCart->next != NULL) {
        tempCart = tempCart->next;
    }
    tempCart->next = newProd;
}

int buy_cart(user *tempUser) {
    int totalPrice = 0;
    Cart *tempCart = tempUser->cart;
    while (tempCart != NULL) {
        totalPrice += ((tempCart->product.price) * (tempCart->product.quantity));
        tempCart = tempCart->next;
    }
    return totalPrice;
}

void welcome_user(user *tempUser) {
    // Welcome menu when a user logs in
welcome_user:
    cout << endl
         << "Welcome " << tempUser->username << "!" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Browse Products" << endl
         << "2. View your cart" << endl
         << "3. Buy your cart" << endl
         << "4. Go Back" << endl
         << "-> ";

    int input;
    cin >> input;
    if (input == 1) {
        display_productList(productList);
    this_one:
        cout << "What would you like to do now?" << endl;
        cout << "1. Add an item to your cart" << endl
             << "2. View your cart" << endl
             << "3. Buy your cart" << endl
             << "4. Go Back" << endl
             << "-> ";
        int input;
        cin >> input;
        if (input == 1) {
            add_item_in_cart(tempUser);
            cout << "Done!" << endl
                 << endl;
            goto this_one;
        } else if (input == 2) {
            view_cart(tempUser);
            goto this_one;
        } else if (input == 3) {
            cout << "Total Price: " << buy_cart(tempUser) << endl << endl;
        } else if (input == 4) {
            goto welcome_user;
        } else {
            cout << "Please enter a valid input!" << endl;
            goto welcome_user;
        }
    } else if (input == 2) {
        view_cart(tempUser);
        goto this_one;
    } else if (input == 3) {
        cout << "Total Price: " << buy_cart(tempUser) << endl << endl;
    } else if (input == 4) {
        welcome_page(userList);
    } else {
        cout << "Please Enter a valid Input!" << endl;
        goto welcome_user;
    }
}

void welcome_page(user *userList) {
    // Welcome page for the website
welcome_page:
    cout << "What would you like to do? " << endl;
    cout << "1. Login" << endl
         << "2. Create new user" << endl
         << "3. Exit" << endl
         << "-> ";
    int input;
    cin >> input;

    if (input == 1) {
        login(userList);
    } else if (input == 2) {
        create_new_user(userList);
    } else if (input == 3) {
        exit(0);
    } else {
        cout << "Please Enter a valid input!" << endl
             << endl;
        goto welcome_page;
    }
    goto welcome_page;
}

int main() {
    cout << endl
         << "Welcome to this shopping website! " << endl
         << endl;
    welcome_page(userList);
}