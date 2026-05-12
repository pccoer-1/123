print("===== Help Desk Expert System =====")

while True:

    print("\nSelect Problem:")
    print("1. Internet Issue")
    print("2. Printer Issue")
    print("3. Password Reset")
    print("4. System Slow")
    print("5. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        print("Solution:")
        print("- Check Wi-Fi connection")
        print("- Restart the router")
        print("- Contact network admin if issue continues")

    elif choice == "2":
        print("Solution:")
        print("- Check printer power")
        print("- Check paper availability")
        print("- Check USB/Wi-Fi connection")

    elif choice == "3":
        print("Solution:")
        print("- Use forgot password option")
        print("- Contact administrator")

    elif choice == "4":
        print("Solution:")
        print("- Close unnecessary applications")
        print("- Restart the system")
        print("- Scan for viruses")

    elif choice == "5":
        print("Exiting Expert System...")
        break

    else:
        print("Invalid choice")