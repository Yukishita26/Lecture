#@title データ生成のパラメータ

th1 = 1.7  #@param {type:"slider", min:0, max:10, step:0.1}
th2 = 2.2  #@param {type:"slider", min:0, max:10, step:0.1}
th3 = 1.2  #@param {type:"slider", min:0, max:10, step:0.1}
th4 = 0.4  #@param {type:"slider", min:0, max:10, step:0.1}


def dist():  # データの分布
    x1 = np.random.normal(0, 1.414)  # normal -> ガウス分布
    x2 = np.random.laplace(0, 1)  # laplace -> ラプラス分布
    return x1, x2


def truey(x1, x2):  # 真の識別関数
    if th1 * x1**2 + th2 * x1 * x2 - th3 * x2**2 < th4:
        return 1
    else:
        return -1


def generate(N):  # N個のサンプルを生成
    X = np.zeros((N, 2))
    y = np.zeros(N, dtype=int)
    for i in range(N):
        x1, x2 = dist()
        y[i] = truey(x1, x2)
        X[i, 0] = x1
        X[i, 1] = x2

    return X, y


def generalization_error(f, M):  # f の汎化誤差をM個のサンプルで近似
    correct = 0
    for i in range(M):
        x1, x2 = dist()
        y = f([[x1, x2]])

        if truey(x1, x2) == 1 and y == 1:
            correct = correct + 1
        elif truey(x1, x2) == -1 and y == -1:
            correct = correct + 1

    return 1 - 1.0 * correct / M
