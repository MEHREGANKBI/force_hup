#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>

void SIGHUP_handler(int signum);
pid_t fork_pid = 0;

int main(int argc, char **argv)
{
	if (argc < 2) {
		errno = EINVAL;
		perror("USAGE: force_hup CMD [CMD OPTIONS]\nError description");
		return EXIT_FAILURE;
	}

	fork_pid = fork();
	if (fork_pid == -1) {
		perror("Forking failed!\n");
		return EXIT_FAILURE;
	} else if (fork_pid == 0) {
		if (execvp(argv[1], argv + 1) == -1) {
			perror("Exec failed!\nError code");
			return EXIT_FAILURE;
		}
	}

	int wait_status;
	struct sigaction new_handler = { 0 };
	new_handler.sa_handler = SIGHUP_handler;
	int sigaction_status =
		sigaction(SIGHUP, &new_handler, (struct sigaction *)NULL);

	if (sigaction_status == -1) {
		perror("Handling SIGHUP failed!\n");
		return EXIT_FAILURE;
	}

	pid_t waitpid_status = waitpid(fork_pid, &wait_status, 0);
	if (waitpid_status == -1) {
		perror("Waiting for the child has failed!\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void SIGHUP_handler(int signum)
{
	if (signum == SIGHUP) {
		kill(fork_pid, SIGTERM);
	}
}