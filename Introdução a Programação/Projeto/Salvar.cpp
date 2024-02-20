void salvar(struct Cad, struct Est, struct Ped)
{
    struct Cad C;
    struct auxCad Pes;
    int i = 0;

    remove("clientes.bin");
    FILE *clientes = fopen("clientes.bin", "ab");
    for (i = 0; i <= 30; i++)
        fwrite(&C, sizeof(struct Cad), 1, clientes);
    
    fclose(clientes);

    struct Est E;
    struct auxEst Prod;

    remove("produtos.bin");
    FILE *produtos = fopen("produtos.bin", "ab");
    for (i = 0; i<=30; i++)
        fwrite(&E, sizeof(struct Est), 1, produtos);
    fclose(produtos);
    
    struct Ped T;
    struct auxPed Ped;

    remove("pedidos.bin");
    FILE *pedidos = fopen("pedidos.bin", "ab");
    for (i = 0; i<=30; i++)
        fwrite(&T, sizeof(struct Ped), 1, pedidos);
    fclose(pedidos);
}