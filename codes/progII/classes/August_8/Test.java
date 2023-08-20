package August_8;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Test {
    public static void main(String[] args){
        /* 
        ArrayList<IEmployee> list = new ArrayList();
    
        Developer developer = new Developer();
        Manager manager = new Manager();

        list.add(developer);
        list.add(manager);
        
        developer.calculateSalary(1000);
        manager.calculateSalary(1000);

        System.out.println(list.size());
        
        System.out.println(developer.getSalary());
        System.out.println(manager.getSalary());
        */

        ArrayList<IEmployee> devs = new ArrayList();

        Developer dev1 = new Developer("Ei", 23, 1000);
        Developer dev2 = new Developer("Murata", 29, 9000);
        Developer dev3 = new Developer("Xiao", 19, 188000);
    
        devs.add(dev1);
        devs.add(dev2);
        devs.add(dev3);

        Scanner menuEntry = new Scanner(System.in);
        System.out.println("Choose an option:\n");

        int option = menuEntry.nextInt();
        
        do {
            System.out.println("Escolha uma opção:");
            System.out.println("1 - Exibir nome");
            System.out.println("2 - Exibir idade");
            System.out.println("3 - Exibir salário do menor para o maior");
            System.out.println("4 - Exibir salário do maior para o menor");
            System.out.println("5 - Sair");

            switch (option) {
                case 1:
                    Collections.sort(devs, new Comparators.NameComparator());
                    break;
                case 2:
                    Collections.sort(devs, new Comparators.AgeComparator());
                    break;
                case 3:
                    Collections.sort(devs, new Comparators.SalaryLowestHighestComparator());
                    break;
                case 4:
                    Collections.sort(devs, new Comparators.SalaryHighestLowestComparator());
                    break;
                default:
                    System.out.println("Opção inválida!");
            }

            if (option >= 1 && option <= 4) {
                System.out.println("Pessoas ordenadas:");
                for (IEmployee developer : devs) {
                    System.out.println(developer);
                }
            }
        } while (option != 5);

        menuEntry.close();
    }


        
        /*
        while(option != 5){
            switch(option){
                case 1:
                    for (int i =0; i<devList.size(); i++){ 
                        System.out.println(devList[i].getName());
                        
                }
            }
        }*/
    }
