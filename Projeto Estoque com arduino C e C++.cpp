using System;
using System.Collections.Generic;

public class ItemEstoque
{
    public string Nome { get; set; }
    public int Quantidade { get; set; }

    public ItemEstoque(string nome, int quantidade)
    {
        Nome = nome;
        Quantidade = quantidade;
    }
}

public class Estoque
{
    private List<ItemEstoque> itens;

    public Estoque()
    {
        itens = new List<ItemEstoque>();
    }

    public void AdicionarItem(string nome, int quantidade)
    {
        itens.Add(new ItemEstoque(nome, quantidade));
        Console.WriteLine($"Item '{nome}' adicionado ao estoque.");
    }

    public void ExibirEstoque()
    {
        Console.WriteLine("\n===== Estoque Atual =====");
        foreach (var item in itens)
        {
            Console.WriteLine($"Nome: {item.Nome}, Quantidade: {item.Quantidade}");
        }
    }
}

class Program
{
    static void Main()
    {
        Estoque estoque = new Estoque();
        bool sair = false;

        while (!sair)
        {
            Console.WriteLine("\n===== Menu Principal =====");
            Console.WriteLine("1. Adicionar Item ao Estoque");
            Console.WriteLine("2. Exibir Estoque");
            Console.WriteLine("0. Sair");

            Console.Write("Escolha uma opção: ");
            string opcao = Console.ReadLine();

            switch (opcao)
            {
                case "1":
                    Console.Write("Digite o nome do item: ");
                    string nome = Console.ReadLine();
                    Console.Write("Digite a quantidade inicial: ");
                    int quantidade;
                    if (int.TryParse(Console.ReadLine(), out quantidade))
                    {
                        estoque.AdicionarItem(nome, quantidade);
                    }
                    else
                    {
                        Console.WriteLine("Quantidade inválida. Tente novamente.");
                    }
                    break;
                case "2":
                    estoque.ExibirEstoque();
                    break;
                case "0":
                    sair = true;
                    break;
                default:
                    Console.WriteLine("Opção inválida. Escolha novamente.");
                    break;
            }
        }

        Console.WriteLine("Encerrando o programa.");
    }
}
