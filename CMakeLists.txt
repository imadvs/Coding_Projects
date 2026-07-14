cmake_minimum_required(VERSION 3.10)
project("P03_Bank System")

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(ATMSystem
        src/main.cpp
        include/clsString.h
        include/clsDate.h
        include/clsPeriod.h
        include/clsUtil.h
        include/clsInputValidate.h
        include/clsInputValidate.h
        include/clsPerson.h
        "include/Clients screens/clsBankClient.h"
        include/clsMainScreen.h
        include/clsScreen.h
        "include/Clients screens/clsClientListScreen.h"
        "include/Clients screens/clsAddNewClientScreen.h"
        "include/Clients screens/clsDeleteClientScreen.h"
        "include/Clients screens/clsUpdateClientScreen.h"
        "include/Clients screens/clsFindClientScreen.h"
        "include/Transactions Screen/clsTransactionsScreen.h"
        include/Manage_Users_Screen/clsManageUsersScreen.h
        "include/Transactions Screen/clsDepositScreen.h"
        "include/Transactions Screen/clsWithdrawScreen.h"
        "include/Transactions Screen/clsTotalBalancesScreen.h"
        include/Manage_Users_Screen/clsListUsersScreen.h
        include/Manage_Users_Screen/clsUser.h
        include/Manage_Users_Screen/clsAddNewUserScreen.h
        include/Manage_Users_Screen/clsDeleteUserScreen.h
        include/Manage_Users_Screen/clsUpdateUserScreen.h
        include/Manage_Users_Screen/clsFindUserScreen.h
        include/Global.h
        include/clsLoginScreen.h
        include/clsLoginRegisterScreen.h
        "include/Transactions Screen/clsTransferScreen.h"
        "include/Transactions Screen/clsTransferLogScreen.h"
        include/InterfaceCommunication.h
        "include/P04 Currency Exchange/clsCurrency.h"
        "include/P04 Currency Exchange/main1 Currency.h"
        "include/P04 Currency Exchange/clsCurrencyExchangeMainScreen.h"
)

target_compile_definitions(ATMSystem PRIVATE
        CLIENTS_FILE_PATH="${CMAKE_SOURCE_DIR}/data/Clients.txt"
        USERS_FILE_PATH="${CMAKE_SOURCE_DIR}/data/Users.txt"
)