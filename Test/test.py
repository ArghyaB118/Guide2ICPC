import numpy as np
import matplotlib.pyplot as plt


N = 4
menMeans = (-0.1047433307, -0.196453684, -1.204876341, -1.2939934)
menStd = (0.00962053752, 0.007274478257, 0.01052006302, 0.04441084988)
womenMeans = (-0.1375608164, -0.5415854388, -0.3006757114, -0.5983190913)
womenStd = (0.0209936922, 0.02258829771, 0.02498202854, 0.009944538289)

womenStd = [x * 3 for x in womenStd]
menStd = [x * 3 for x in menStd]

ind = np.arange(N)    # the x locations for the groups
width = 0.35       # the width of the bars: can also be len(x) sequence

p1 = plt.bar(ind+width, menMeans, width, yerr=menStd, color="yellow", label="kras KO")
p2 = plt.bar(ind+2*width, womenMeans, width, yerr=womenStd, color="cyan", label="Kras mutant")

plt.ylim(-2,0)
plt.title('Tumor cells: T cells' + '\n', fontsize=16)
plt.ylabel('negative log 2 fold change in fluorescence' + '\n' + '(measured by cyquant assay)', fontsize=16)
#plt.xlabel('Tumor cells: T cells', fontsize=16)
plt.xticks(ind+2*width, ('1:2', '1:5', '1:10', '1:20'))
plt.yticks(np.arange(-2, 0.5, 0.5))
plt.tick_params(labelbottom=False,labeltop=True)
#plt.legend(bbox_to_anchor=(1,0), loc="lower right", (p1[0], p2[0]), ('Men', 'Women'))
plt.legend(bbox_to_anchor=(1,0), loc="lower right")
plt.show()
