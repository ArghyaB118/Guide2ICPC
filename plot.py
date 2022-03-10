import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import spline
from scipy.interpolate import make_interp_spline, BSpline


memoryMB = np.array([1, 2, 4, 8, 16, 32, 64])
memoryMB = np.log(memoryMB)
mulTimeCA = np.array([1747, 1725, 1710, 1699, 1697, 1697, 1696])
mulTimeNCA = np.array([1847, 1755, 1736, 1714, 1712, 1711, 1707])

memoryAxis = np.linspace(memoryMB.min(), memoryMB.max(), 100)
mulTimeCASmooth = spline(memoryMB, mulTimeCA, memoryAxis)
mulTimeNCASmooth = spline(memoryMB, mulTimeNCA, memoryAxis)

fig1 = plt.figure()
plt.plot(memoryAxis, mulTimeCASmooth, label = 'CA')
plt.plot(memoryAxis, mulTimeNCASmooth, label = 'N-CA')

fig1.suptitle('CA and N-CA multiplication time taken per log of cache size')
plt.xlabel('log of memory (MiB) in cache')
plt.ylabel('total running time in seconds')
plt.legend(loc = 'best')

#--------------------------------


iowaitTimeCA = np.array([26.5, 14.8, 5.5, 4.1, 1.8, 1.4, 0])
iowaitTimeNCA = np.array([96, 31, 19, 7, 5, 2, 1.8])
iowaitTimeCASmooth = spline(memoryMB, iowaitTimeCA, memoryAxis)
iowaitTimeNCASmooth = spline(memoryMB, iowaitTimeNCA, memoryAxis)

fig2 = plt.figure()
plt.plot(memoryAxis, iowaitTimeCASmooth, label = 'CA')
plt.plot(memoryAxis, iowaitTimeNCASmooth, label = 'N-CA')

fig2.suptitle('CA and N-CA io wait time taken per log of cache size')
plt.xlabel('log of memory (MiB) in cache')
plt.ylabel('io wait time taken in seconds')
plt.legend(loc = 'best')


#--------------------------------


bytesReadCA = np.array([26.5, 14.8, 5.5, 4.1, 1.8, 1.4, 0])
bytesReadNCA = np.array([96, 31, 19, 7, 5, 2, 1.8])
bytesReadCASmooth = spline(memoryMB, bytesReadCA, memoryAxis)
bytesReadNCASmooth = spline(memoryMB, bytesReadNCA, memoryAxis)

fig5 = plt.figure()
plt.plot(memoryAxis, bytesReadCASmooth, label = 'CA')
plt.plot(memoryAxis, bytesReadNCASmooth, label = 'N-CA')

fig5.suptitle('CA and N-CA bytes read per log of cache size')
plt.xlabel('log of memory (MiB) in cache')
plt.ylabel('bytes Read in MiB')
plt.legend(loc = 'best')




#--------------------------------


memoryMB = np.array([4, 8, 16, 32, 64])
memoryMB = np.log(memoryMB)
mulTimeStxxl = np.array([1710, 1699, 1697, 1697, 1696])
mulTimeCgroup = np.array([1062, 1045, 1042, 1039, 1037])

memoryAxis = np.linspace(memoryMB.min(), memoryMB.max(), 100)
mulTimeStxxlSmooth = spline(memoryMB, mulTimeStxxl, memoryAxis)
mulTimeCgroupSmooth = spline(memoryMB, mulTimeCgroup, memoryAxis)

fig3 = plt.figure()
plt.plot(memoryAxis, mulTimeStxxlSmooth, label = 'Stxxl')
plt.plot(memoryAxis, mulTimeCgroupSmooth, label = 'Cgroup')

fig3.suptitle('Stxxl and Cgroup multiplication time taken per log of cache size')
plt.xlabel('log of memory (MiB) in cache')
plt.ylabel('time taken in seconds')
plt.legend(loc = 'best')

#--------------------------------

bytesReadStxxl = np.array([160, 160, 80, 72, 0])
bytesReadCgroup = np.array([574, 170, 101, 53, 6.3])

bytesReadStxxlSmooth = spline(memoryMB, bytesReadStxxl, memoryAxis)
bytesReadCgroupSmooth = spline(memoryMB, bytesReadCgroup, memoryAxis)

fig4 = plt.figure()
plt.plot(memoryAxis, bytesReadStxxlSmooth, label = 'Stxxl')
plt.plot(memoryAxis, bytesReadCgroupSmooth, label = 'Cgroup')

fig4.suptitle('Stxxl and Cgroup bytes Read statistics per log of cache size')
plt.xlabel('log of memory (MiB) in cache')
plt.ylabel('bytes read in MiB')
plt.legend(loc = 'best')


#--------------------------------
bytesReadmmapCA = np.array([4050120704, 2551332864, 1415127040, 725622784, 1892352])
bytesReadmmapCA = bytesReadmmapCA / (1024*1024)
bytesReadmmapNCA = np.array([7373832192, 4653068288, 3300589568, 1995390976, 952922112])
bytesReadmmapNCA = bytesReadmmapNCA / (1024*1024)
memoryMB = np.array([56, 128, 256, 512, 1024])
#memoryMB = np.log(memoryMB)
#memoryAxis = np.linspace(memoryMB.min(), memoryMB.max(), 100)
#bytesReadmmapCASmooth = spline(memoryMB, bytesReadStxxl, memoryAxis)
#bytesReadmmapNCASmooth = spline(memoryMB, bytesReadCgroup, memoryAxis)
fig6 = plt.figure()
plt.scatter(memoryMB, bytesReadmmapCA, label = 'CA')
plt.scatter(memoryMB, bytesReadmmapNCA, label = 'NCA')
#plt.plot(memoryAxis, bytesReadmmapCASmooth, label = 'CA')
#plt.plot(memoryAxis, bytesReadmmapNCASmooth, label = 'NCA')
fig6.suptitle('CA and NCA MBytes read per cache size using file backed mmap')
plt.xlabel('memory (MiB) in cache')
plt.ylabel('bytes read in MiB')
plt.legend(loc = 'best')


#--------------------------------
bytesWritemmapCA = np.array([2640273408, 2002616320, 1555611648, 1417306112, 1941098496])
bytesWritemmapCA = bytesWritemmapCA / (1024*1024)
bytesWritemmapNCA = np.array([9529745408, 6546247680, 4603215872, 4043464704, 4188782592])
bytesWritemmapNCA = bytesWritemmapNCA / (1024*1024)
#bytesWritemmapCASmooth = spline(memoryMB, bytesReadStxxl, memoryAxis)
#bytesWritemmapNCASmooth = spline(memoryMB, bytesReadCgroup, memoryAxis)
fig7 = plt.figure()
plt.scatter(memoryMB, bytesWritemmapCA, label = 'CA')
plt.scatter(memoryMB, bytesWritemmapNCA, label = 'NCA')
#plt.plot(memoryAxis, bytesWritemmapCASmooth, label = 'CA')
#plt.plot(memoryAxis, bytesWritemmapNCASmooth, label = 'NCA')
fig7.suptitle('CA and NCA MBytes Written per cache size using file backed mmap')
plt.xlabel('memory (MiB) in cache')
plt.ylabel('bytes written in MiB')
plt.legend(loc = 'best')

plt.show()