
//–≈∫≈¡ø


void P(int semid) {
	struct sembuf sb[1];
	sb[0].sem_num = 0;
	sb[0].sem_op = -1;
	sb[0].sem_flg = 0;
	semop(semid, sb, 1);
}

void V(int semid) {
	struct sembuf sb[1];
	sb[0].sem_num = 0;
	sb[0].sem_op = 1;
	sb[0].sem_flg = 0;
	semop(semid, sb, 1);
}

int main() {
	int shmid = shmget(ftok(".", 'a'), sizeof(int), IPC_CREAT | 0644);
	int semw = semget(ftok(".", 'a'), 1, IPC_CREAT | 0644);
	int semr = semget(ftok(".", 'B'), 1, IPC_CREAT | 0644);

	union semun su;
	su.val = 0;

	semctl(semr, 0, SETVAL, su);
	su.val = 1;
	semctl(semw, 0, SETVAL, su);

	int* p = (int*)shmat(shmid, NULL, 0);
	int i = 0;
	while (1) {
		P(semw);
	}

}