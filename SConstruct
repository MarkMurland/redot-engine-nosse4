# Set x86 CPU instruction sets to use by the compiler's autovectorization.
if env["arch"] == "x86_64":
    # x86_64 CPUs are required to support SSE2, which is the baseline for 64-bit x86.
    # Avoid forcing newer ISA levels that would reject older 64-bit systems.
    if env.msvc and not methods.using_clang(env):
        env.Append(CCFLAGS=["/arch:SSE2"])
    else:
        env.Append(CCFLAGS=["-msse2"])
elif env["arch"] == "x86_32":
    # Be more conservative with instruction sets on 32-bit x86 to improve compatibility.
    # SSE and SSE2 are present on all CPUs that support 64-bit, even if running a 32-bit OS.
    if env.msvc and not methods.using_clang(env):
        env.Append(CCFLAGS=["/arch:SSE2"])
    else:
        # Use `-mfpmath=sse` to use SSE for floating-point math, which is more stable than x87.
        # `-mstackrealign` is needed for it to work.
        env.Append(CCFLAGS=["-msse2", "-mfpmath=sse", "-mstackrealign"])
