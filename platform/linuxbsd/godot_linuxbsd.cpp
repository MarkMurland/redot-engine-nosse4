	#if defined(__x86_64) || defined(__x86_64__)
		// x86_64 requires at least SSE2; do not reject older 64-bit CPUs.
	#endif

#if defined(SANITIZERS_ENABLED)
	// Note: Set stack size to be at least 30 MB (vs 8 MB default) to avoid overflow, address sanitizer can increase stack usage up to 3 times.
	struct rlimit stack_lim = { 0x1E00000, 0x1E00000 };
	setrlimit(RLIMIT_STACK, &stack_lim);
#endif

	OS_LinuxBSD os;
