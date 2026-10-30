# Set x86 CPU instruction sets to use by the compiler's autovectorization.
if env["arch"] == "x86_64":
    # On 64-bit x86, keep the base x86_64 baseline instead of forcing SSE4.2.
    # This preserves compatibility with older x86_64 CPUs while still using
    # the standard SSE2 baseline for 64-bit x86.
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
