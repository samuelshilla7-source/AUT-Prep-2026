from datetime import datetime
import json

class BankAccount:
    
    def __init__ (self, name, entered_pin):
        self.name = name
        self.balance = 0
        self.pin = entered_pin
        self.transactions = []

    def authenticate(self, entered_pin):
         return entered_pin == self.pin
    
    def log(self, message):
        time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        self.transactions.append(f"{time} | {message}")

    def deposit(self, amount):
        if amount > 0:
         self.balance += amount
         self.log(f"DEPOSIT +{amount} balance={self.balance}")
         print(f"{self.name} deposited {amount}. New balance: {self.balance}")
         
        else:
            print("Amount must be greater than 0")
            self.log("FAILED_DEPOSIT invalid_amount")


    def withdraw(self, amount, entered_pin):
         
        if  not self.authenticate(entered_pin):
            print("Incorrect Pin")
            self.log("FAILED_WITHDRAW wrong_pin")
            return
        elif amount > self.balance:
            self.log(f"FAILED_WITHDRAW insufficient amount={amount}")
            print(f"{self.name} has insufficient funds for withdrawal. Current balance: {self.balance}")
        else:
            self.balance -= amount
            self.log(f"WITHDRAW -{amount} balance={self.balance}")
            print(f"{self.name} withdrew {amount}. New balance: {self.balance}")
    
    def transfer(self, other_account, amount, entered_pin):

        if not self.authenticate(entered_pin):
            print("Incorrect Pin")
            self.log("FAILED_TRANSFER wrong_pin")
            return
        
        elif amount > self.balance:
            self.log(f"FAILED_TRANSFER insufficient funds - {self.balance}")
            print("Transfer failed, insufficient funds,")
        else:
            self.balance -= amount
            other_account.balance += amount
            self.log(f"TRANSFER_OUT -{amount} to={other_account.name}")
            other_account.log(f"TRANSFER_IN +{amount} from={self.name}")
            print(f"{self.name} has successfully sent {amount} to {other_account.name}")

    
    def display(self):
        print(f"{self.name} has the following balance {self.balance}")

    def show_transactions(self):
     print(f"\n--- {self.name} Transactions ---")

     if not self.transactions:
          print("No transactions yet.")
     else:
         for t in self.transactions:
            print(t)
    def to_dict(self):
     return {
        "name": self.name,
        "balance": self.balance,
        "pin": self.pin,
        "transactions": self.transactions
        }
    
    @classmethod
    def from_dict(cls, data):
     obj = cls(data["name"], data["pin"])
     obj.balance = data["balance"]
     obj.transactions = data["transactions"]
     return obj

class BankSystem:
    
    def __init__(self):
        self.accounts = {}
        
    def create_account(self, name, pin):

        if name in self.accounts:
            print("Account already exists")

        else:
            self.accounts[name] = BankAccount(name, pin)
            print(f"Created account for {name}")

    def get_account(self, name):
        
        return self.accounts.get(name)
        
    def transfer(self, sender_name, receiver_name, amount, entered_pin):

      if sender_name not in self.accounts:
        print(f"Sender '{sender_name}' not found.")
        return

      if receiver_name not in self.accounts:
        print(f"Receiver '{receiver_name}' not found.")
        return

      sender = self.accounts[sender_name]
      receiver = self.accounts[receiver_name]

      sender.transfer(receiver, amount, entered_pin)

    def display_all_accounts(self):
        for i in self.accounts.values():
            i.display()
            
    def save_to_file(self, filename):
        data = {}

        for name, account in self.accounts.items():
            data[name] = account.to_dict()

        with open(filename, "w") as file:
            json.dump(data, file, indent=4)

    def load_from_file(self, filename):
        try:
            with open(filename, "r") as file:
                 data = json.load(file)

            for name, acc_data in data.items():
                 self.accounts[name] = BankAccount.from_dict(acc_data)

        except FileNotFoundError:
             print("No saved data found.")
    
        
bank = BankSystem()  

bank.create_account("Sam", 4747)
bank.create_account("Sophia", 3939)

bank.get_account("Sam").deposit(1000)
bank.get_account("Sophia").deposit(500)
bank.get_account("Sam").withdraw(300, 4747)
bank.transfer("Sam", "Sophia", 200, 4747)

bank.display_all_accounts()