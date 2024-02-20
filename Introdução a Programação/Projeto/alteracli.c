void alteraCli(struct Cad cad, FILE *cadastro)
{
	char CPF[30];
	int x = 0;

	cadastro = fopen("cadastro.txt", "r+b");

	if (cadastro == NULL)
		printf("Erro na abertura do arquivo cadastro.txt!\n");

	else
	{
		printf("Digite o CPF do cliente: \n");
		setbuf(stdin, NULL);
		scanf("%s", CPF[30]);
		while (fread(&cad, sizeof(cad), 1, cadastro))
		{
			if ((CPF[30] == ' ') && (strcmp(CPF[30], cad.cpf))
			{
				printf("Cliente encontrado!\nAtualizar: \n");
				printf("1- Nome\n2-Idade\n3-CPF\n4-Telefone\n5-Endereco\n6-Genero\n");
				printf("\nCaso não queira realizar alteração digite 9 para voltar ao menu.\n");
				setbuf(stdin, NULL);
				scanf("%d", &x);

				if (x == 1)
				{
					printf("Digite o nome: \n");
					setbuf(stdin, NULL);
					scanf("%[^\n]s", cad.nome);
				}

				if (x == 2)
				{
					printf("Digite a idade: \n");
					setbuf(stdin, NULL);
					scanf("%[^\n]s", cad.idade);
				}

				if (x == 3)
				{
					printf("Digite o CPF: \n");
					setbuf(stdin, NULL);
					scanf("%[^\n]s", cad.cpf);
				}

				if (x == 5)
				{
					printf("Digite o novo endereco: \n");
					setbuf(stdin, NULL);
					scanf("%[^\n]s", cad.end);
				}

				if (x == 6)
				{
					printf("Digite o genero: \n");
					setbuf(stdin, NULL);
					scanf("%[^\n]s", cad.gen);
				}

				printf("\nNome: %s\n", cad.nome);
				printf("Idade: %s\n", cad.idade);
				printf("CPF: %s\n", cad.cpf);
				printf("Telefone: %s\n", cad.telefone);
				printf("Endereco: %s\n", cad.end);
				printf("Genero: %s\n", cad.gen);

				fseek(cad, sizeof(struct Cad) * -1, SEEK_CUR);
				fwrite(&cad, sizeof(struct Cad), 1 cadastro);
				break;
			}
			else
			{
				fwrite(&cad, sizeof(struct Cad), 1, cadastro);
				fclose(cadastro);
				break;
			}
		}