cmake_minimum_required(VERSION 3.10)
project("Project 1 - Utility Library")

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
        include/clsBankClient.h
        include/clsMainScreen.h
        include/clsScreen.h
        include/clsClientListScreen.h
        include/clsAddNewClientScreen.h
        include/clsDeleteClientScreen.h
        include/clsUpdateClientScreen.h
        include/clsFindClientScreen.h
        "include/Transactions Screen/clsTransactionsScreen.h"
        include/Manage_Users_Screen/clsManageUsersScreen.h
        "include/Transactions Screen/clsDepositScreen.h"
        "include/Transactions Screen/clsWithdrawScreen.h"
        "include/Transactions Screen/clsTotalBalancesScreen.h"
)

target_compile_definitions(ATMSystem PRIVATE
        CLIENTS_FILE_PATH="${CMAKE_SOURCE_DIR}/data/Clients.txt"
)